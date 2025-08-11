/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:24:05 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/10 20:32:30 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	copy_command(t_command *src, t_command *dst)
{
	dst->ra = src->ra;
	dst->rb = src->rb;
	dst->rra = src->rra;
	dst->rrb = src->rrb;
	dst->rr = src->rr;
	dst->rrr = src->rrr;
	dst->all = src->all;
}

static void	process_r(t_command *r)
{
	r->rr = ft_min(r->ra, r->rb);
	r->ra -= r->rr;
	r->rb -= r->rr;
	r->rrr = 0;
	r->rra = 0;
	r->rrb = 0;
	r->all = r->rr + r->ra + r->rb;
}

static void	process_rr(t_command *rr)
{
	rr->rrr = ft_min(rr->rra, rr->rrb);
	rr->rra -= rr->rrr;
	rr->rrb -= rr->rrr;
	rr->rr = 0;
	rr->ra = 0;
	rr->rb = 0;
	rr->all = rr->rrr + rr->rra + rr->rrb;
}

static void	process_nor(t_command *nor)
{
	if (nor->ra > nor->rra)
		nor->ra = 0;
	else
		nor->rra = 0;
	if (nor->rb > nor->rrb)
		nor->rb = 0;
	else
		nor->rrb = 0;
	nor->all = nor->ra + nor->rra + nor->rb + nor->rrb;
}

void	sum_cost(t_node *tmp)
{
	t_command	r;
	t_command	rr;
	t_command	nor;

	copy_command(&tmp->command, &r);
	copy_command(&tmp->command, &rr);
	copy_command(&tmp->command, &nor);
	process_r(&r);
	process_rr(&rr);
	process_nor(&nor);
	if (r.all < rr.all && r.all < nor.all)
		copy_command(&r, &tmp->command);
	else if (rr.all < r.all && rr.all < nor.all)
		copy_command(&rr, &tmp->command);
	else
		copy_command(&nor, &tmp->command);
}
