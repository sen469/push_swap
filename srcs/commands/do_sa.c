/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 18:35:01 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/15 19:07:05 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sa(t_node *st_a)
{
	t_node	*first;
	t_node	*second;

	if (st_a->next != st_a->prev)
	{
		first = st_a->next;
		second = first->next;
		st_a->next = second;
		first->next = second->next;
		second->next->prev = first;
		second->prev = st_a;
		second->next = first;
		first->prev = second;
		write(1, "sa\n", 3);
	}
}
