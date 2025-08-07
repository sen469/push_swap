/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 18:34:40 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/06 19:01:10 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_ra(t_node *st_a)
{
	t_node	*tmp_a;

	// スタックに要素が2つ以上があることを確認する
	if  (st_a->next != st_a->prev)
	{
		tmp_a = st_a->next;
		st_a->next = tmp_a->next;
		st_a->next->prev = st_a;
		tmp_a->next = st_a;
		tmp_a->prev = st_a->prev;
		st_a->prev->next = tmp_a;
		st_a->prev = tmp_a;
		write(1, "ra\n", 3);
	}
}
