/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_sub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:54:51 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/16 16:11:03 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_node_command(t_node *st)
{
	t_node	*tmp;

	tmp = st->next;
	while (tmp != st)
	{
		tmp->command.rra = 0;
		tmp->command.ra = 0;
		tmp->command.rrb = 0;
		tmp->command.rb = 0;
		tmp->command.rr = 0;
		tmp->command.rrr = 0;
		tmp->command.all = 0;
		tmp = tmp->next;
	}
}

void	make_stack_b(t_node *st_a, t_node *st_b, t_vec *lis)
{
	int	st_a_size;
	int	i;

	i = 0;
	st_a_size = get_stack_size(st_a);
	while (i < st_a_size)
	{
		if (!ft_binary_search(lis->arr, lis->size, st_a->next->data))
		{
			do_pb(st_a, st_b, 1);
		}
		else
		{
			do_ra(st_a, 1);
		}
		i++;
	}
}

void	cost_of_top_b(t_node *st_b)
{
	int		cost_r;
	int		st_size_b;
	t_node	*tmp;

	st_size_b = get_stack_size(st_b);
	tmp = st_b->next;
	cost_r = 0;
	while (tmp != st_b)
	{
		tmp->command.rb = cost_r;
		tmp->command.rrb = st_size_b - cost_r;
		cost_r++;
		tmp = tmp->next;
	}
}

t_node	*chose_min_cost(t_node *st)
{
	t_node		*tmp;
	t_command	cmd;
	int			mn;
	t_node		*ret;

	mn = INT_MAX;
	tmp = st->next;
	ret = NULL;
	while (tmp != st)
	{
		sum_cost(tmp);
		cmd = tmp->command;
		if (cmd.all < mn)
		{
			mn = cmd.all;
			ret = tmp;
		}
		tmp = tmp->next;
	}
	return (ret);
}

int	get_min_index(t_node *st)
{
	t_node	*tmp;
	int		mn_index;
	int		cost;
	int		res;

	tmp = st->next;
	mn_index = INT_MAX;
	cost = 0;
	while (tmp != st)
	{
		if (tmp->index < mn_index)
		{
			res = cost;
			mn_index = tmp->index;
		}
		cost++;
		tmp = tmp->next;
	}
	return (res);
}
