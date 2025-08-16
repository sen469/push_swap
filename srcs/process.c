/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:47:13 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/16 16:10:50 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include "struct.h"
#include <limits.h>
#include <stdlib.h>

static void	set_insertion_cost(t_node *node_b, t_node *st_a, \
		int size_a, int cost_r)
{
	t_node	*tmp_a;

	tmp_a = st_a->next;
	while (tmp_a != st_a)
	{
		if (tmp_a->prev->index < node_b->index && node_b->index < tmp_a->index)
		{
			node_b->command.ra = cost_r;
			node_b->command.rra = size_a - cost_r;
			return ;
		}
		tmp_a = tmp_a->next;
		cost_r++;
	}
	if (st_a->prev->index < node_b->index && node_b->index < st_a->next->index)
	{
		node_b->command.ra = 0;
		node_b->command.rra = size_a;
	}
	else
	{
		cost_r = get_min_index(st_a);
		node_b->command.ra = cost_r;
		node_b->command.rra = size_a - cost_r;
	}
}

void	cost_of_b2a(t_node *st_a, t_node *st_b)
{
	int		st_size_a;
	t_node	*tmp_b;
	int		cost_r;

	cost_r = 0;
	st_size_a = get_stack_size(st_a);
	tmp_b = st_b->next;
	while (tmp_b != st_b)
	{
		set_insertion_cost(tmp_b, st_a, st_size_a, cost_r);
		tmp_b = tmp_b->next;
	}
}

static void	push_b_to_a(t_node *st_a, t_node *st_b)
{
	t_node	*min_cost_node;

	while (st_b->next != st_b)
	{
		init_node_command(st_b);
		cost_of_top_b(st_b);
		cost_of_b2a(st_a, st_b);
		min_cost_node = chose_min_cost(st_b);
		do_command(min_cost_node, st_a, st_b);
		do_pa(st_a, st_b, 1);
	}
}

static void	finalize_stack_a(t_node *st_a)
{
	int	size;
	int	cost;

	size = get_stack_size(st_a);
	cost = get_min_index(st_a);
	if (cost < size - cost)
	{
		while (cost--)
			do_ra(st_a, 1);
	}
	else
	{
		while (size - cost > 0)
		{
			do_rra(st_a, 1);
			cost++;
		}
	}
}

void	process(t_vec *vec, t_node *st_a, t_node *st_b)
{
	t_vec	lis;

	if (vec->size <= 5)
	{
		process_sub(vec->size, st_a, st_b);
		return ;
	}
	process_lis(vec, &lis);
	if (lis.size == vec->size)
	{
		free_all(vec->arr, st_a, st_b);
		free_arr(&lis.arr);
		exit(EXIT_SUCCESS);
	}
	make_stack_b(st_a, st_b, &lis);
	free_arr(&lis.arr);
	free_arr(&vec->arr);
	push_b_to_a(st_a, st_b);
	finalize_stack_a(st_a);
}
