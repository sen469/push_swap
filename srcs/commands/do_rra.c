/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 18:34:50 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/06 19:01:12 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rra(t_node *st_a)
{
	t_node	*tmp_a;

	if (st_a->next != st_a->prev)
	{
		tmp_a = st_a->prev;
		st_a->prev = tmp_a->prev;
		st_a->prev->next = st_a;
		tmp_a->prev = st_a;
		tmp_a->next = st_a->next;
		st_a->next->prev = tmp_a;
		st_a->next = tmp_a;
		write(1, "rra\n", 4);
	}
}
