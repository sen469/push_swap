/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 11:44:05 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/08 11:45:51 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_ss(t_node *st_a, t_node *st_b)
{
	t_node	*first_a;
	t_node	*second_a;
	t_node	*first_b;
	t_node	*second_b;

	// 要素が2つ以上あることを確認
	if (st_a->next != st_a->prev && st_b->next != st_b->prev)
	{
		first_a = st_a->next;
		second_a = first_a->next;
		st_a->next = second_a;
		first_a->next = second_a->next;
		second_a->next->prev = first_a;
		second_a->prev = st_a;
		second_a->next = first_a;
		first_a->prev = second_a;
		first_b = st_b->next;
		second_b = first_b->next;
		st_b->next = second_b;
		first_b->next = second_b->next;
		second_b->next->prev = first_b;
		second_b->prev = st_b;
		second_b->next = first_b;
		first_b->prev = second_b;
		write(1, "ss\n", 3);
	}
}
