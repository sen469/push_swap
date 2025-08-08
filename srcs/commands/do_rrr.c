/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 18:34:57 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/06 19:01:15 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rrr(t_node *st_a, t_node *st_b)
{
	t_node	*tmp_a;
	t_node	*tmp_b;

	if (st_a->next != st_a->prev && st_b->next != st_b->prev)
	{
		tmp_a = st_a->prev;
		st_a->prev = tmp_a->prev;
		st_a->prev->next = st_a;
		tmp_a->prev = st_a;
		tmp_a->next = st_a->next;
		st_a->next->prev = tmp_a;
		st_a->next = tmp_a;
		tmp_b = st_b->prev;
		st_b->prev = tmp_b->prev;
		st_b->prev->next = st_b;
		tmp_b->prev = st_b;
		tmp_b->next = st_b->next;
		st_b->next->prev = tmp_b;
		st_b->next = tmp_b;
		write(1, "rrr\n", 4);
	}
}
