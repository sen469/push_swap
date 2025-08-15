/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 18:35:03 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/15 19:07:10 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sb(t_node *st_b)
{
	t_node	*first;
	t_node	*second;

	if (st_b->next != st_b->prev)
	{
		first = st_b->next;
		second = first->next;
		st_b->next = second;
		first->next = second->next;
		second->next->prev = first;
		second->prev = st_b;
		second->next = first;
		first->prev = second;
		write(1, "sb\n", 3);
	}
}
