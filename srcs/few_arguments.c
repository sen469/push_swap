/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   few_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 19:36:04 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/15 19:36:51 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three_nodes(t_node *st_a, t_node *first, t_node *second,
		t_node *third)
{
	if (first->index > second->index && second->index < third->index
		&& first->index < third->index)
		do_sa(st_a);
	else if (first->index > second->index && second->index > third->index)
	{
		do_sa(st_a);
		do_rra(st_a);
	}
	else if (first->index > second->index && second->index < third->index
		&& first->index > third->index)
		do_ra(st_a);
	else if (first->index < second->index && second->index > third->index
		&& first->index < third->index)
	{
		do_sa(st_a);
		do_ra(st_a);
	}
	else if (first->index < second->index && second->index > third->index
		&& first->index > third->index)
		do_rra(st_a);
}

static void	process_3(t_node *st_a)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = st_a->next;
	second = first->next;
	third = second->next;
	sort_three_nodes(st_a, first, second, third);
}

static void	process_4(t_node *st_a, t_node *st_b)
{
	move_target_to_top(st_a, 0);
	do_pb(st_a, st_b);
	process_3(st_a);
	do_pa(st_a, st_b);
}

static void	process_5(t_node *st_a, t_node *st_b)
{
	move_target_to_top(st_a, 0);
	do_pb(st_a, st_b);
	move_target_to_top(st_a, 1);
	do_pb(st_a, st_b);
	process_3(st_a);
	do_pa(st_a, st_b);
	do_pa(st_a, st_b);
}

void	process_sub(int size, t_node *st_a, t_node *st_b)
{
	if (size <= 1)
		return ;
	else if (size == 2)
	{
		if (st_a->next->index > st_a->next->next->index)
			do_sa(st_a);
	}
	else if (size == 3)
		process_3(st_a);
	else if (size == 4)
		process_4(st_a, st_b);
	else if (size == 5)
		process_5(st_a, st_b);
}
