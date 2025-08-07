/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 18:34:46 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/06 19:01:13 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "struct.h"

void	do_rr(t_node *st_a, t_node *st_b)
{
	t_node	*tmp_a;
	t_node	*tmp_b;

	if (st_a->next != st_a->prev && st_b->next != st_b->prev)
	{
		tmp_a = st_a->next;
		st_a->next = tmp_a->next;
		st_a->next->prev = st_a;
		tmp_a->next = st_a;
		tmp_a->prev = st_a->prev;
		st_a->prev->next = tmp_a;
		st_a->prev = tmp_a;
		tmp_b = st_b->next;
		st_b->next = tmp_b->next;
		st_b->next->prev = st_b;
		tmp_b->next = st_b;
		tmp_b->prev = st_b->prev;
		st_b->prev->next = tmp_b;
		st_b->prev = tmp_b;
		write(1, "rr\n", 3);
	}
}
