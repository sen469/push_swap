/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 19:37:22 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/16 16:11:14 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_target_to_top(t_node *st_a, int target_index)
{
	t_node	*node;
	int		pos;
	int		size;

	pos = 0;
	size = get_stack_size(st_a);
	node = st_a->next;
	while (node != st_a)
	{
		if (node->index == target_index)
			break ;
		pos++;
		node = node->next;
	}
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			do_ra(st_a, 1);
	}
	else
	{
		while (pos++ < size)
			do_rra(st_a, 1);
	}
}

int	is_sorted(t_node *st_a)
{
	t_node	*tmp;

	if (get_stack_size(st_a) <= 1)
		return (1);
	tmp = st_a->next;
	while (tmp->next != st_a)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
