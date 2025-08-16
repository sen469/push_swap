/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 18:34:52 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/16 16:08:38 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rrb(t_node *st_b, int flag)
{
	t_node	*tmp_b;

	if (st_b->next != st_b->prev)
	{
		tmp_b = st_b->prev;
		st_b->prev = tmp_b->prev;
		st_b->prev->next = st_b;
		tmp_b->prev = st_b;
		tmp_b->next = st_b->next;
		st_b->next->prev = tmp_b;
		st_b->next = tmp_b;
		if (flag)
			write(1, "rrb\n", 4);
	}
}
