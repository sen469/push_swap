/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:54:54 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/16 16:09:31 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "struct.h"

static void	do_all(t_command *tmp, t_node *st_a, t_node *st_b)
{
	while (tmp->rr--)
		do_rr(st_a, st_b, 1);
	while (tmp->rrr--)
		do_rrr(st_a, st_b, 1);
	while (tmp->ra--)
		do_ra(st_a, 1);
	while (tmp->rb--)
		do_rb(st_b, 1);
	while (tmp->rra--)
		do_rra(st_a, 1);
	while (tmp->rrb--)
		do_rrb(st_b, 1);
}

void	do_command(t_node *node, t_node *st_a, t_node *st_b)
{
	t_command	*tmp;

	tmp = &node->command;
	if (tmp->ra && tmp->rb)
	{
		tmp->rr = ft_min(tmp->ra, tmp->rb);
		tmp->ra -= tmp->rr;
		tmp->rb -= tmp->rr;
	}
	if (tmp->rra && tmp->rrb)
	{
		tmp->rrr = ft_min(tmp->rra, tmp->rrb);
		tmp->rra -= tmp->rrr;
		tmp->rrb -= tmp->rrr;
	}
	do_all(tmp, st_a, st_b);
}
