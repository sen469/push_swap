/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 18:34:30 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/06 23:52:39 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "struct.h"

void	do_pa(t_node *st_a, t_node *st_b)
{
	t_node *tmp;
	// st_bが空でないことを確認
	if (st_b->next != st_b)
	{

		tmp = st_b->next;
		st_b->next = tmp->next;
		st_b->next->prev = st_b;
		tmp->prev = st_a;
		tmp->next = st_a->next;
		st_a->next->prev = tmp;
		st_a->next = tmp;
		write(1, "pa\n", 3);
	}
}
