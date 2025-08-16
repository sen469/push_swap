/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 18:34:57 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/16 16:43:19 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rrr(t_node *st_a, t_node *st_b, int flag)
{
	if (st_a->next != st_a->prev && st_b->next != st_b->prev)
	{
		do_rra(st_a, 0);
		do_rrb(st_b, 0);
		if (flag)
			write(1, "rrr\n", 4);
	}
}
