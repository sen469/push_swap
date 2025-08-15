/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 19:37:22 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/15 19:39:46 by ssawa            ###   ########.fr       */
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
			do_ra(st_a);
	}
	else
	{
		while (pos++ < size)
			do_rra(st_a);
	}
}
