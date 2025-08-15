/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 18:34:43 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/15 19:14:43 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rb(t_node *st_b)
{
	t_node	*tmp_b;

	if (st_b->next != st_b->prev)
	{
		tmp_b = st_b->next;
		st_b->next = tmp_b->next;
		st_b->next->prev = st_b;
		tmp_b->next = st_b;
		tmp_b->prev = st_b->prev;
		st_b->prev->next = tmp_b;
		st_b->prev = tmp_b;
		write(1, "rb\n", 3);
	}
}
