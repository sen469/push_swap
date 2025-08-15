/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 18:34:37 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/15 19:09:16 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_pb(t_node *st_a, t_node *st_b)
{
	t_node	*tmp;

	if (st_a->next != st_a)
	{
		tmp = st_a->next;
		st_a->next = tmp->next;
		st_a->next->prev = st_a;
		tmp->prev = st_b;
		tmp->next = st_b->next;
		st_b->next->prev = tmp;
		st_b->next = tmp;
		write(1, "pb\n", 3);
	}
}
