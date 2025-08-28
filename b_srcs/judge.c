/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   judge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 22:17:10 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/16 16:12:04 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft/libft.h"
#include "push_swap.h"

int	do_command_checker(t_node *st_a, t_node *st_b, char *cmd)
{
	if (!ft_strcmp(cmd, RA))
		do_ra(st_a, 0);
	else if (!ft_strcmp(cmd, RB))
		do_rb(st_b, 0);
	else if (!ft_strcmp(cmd, RR))
		do_rr(st_a, st_b, 0);
	else if (!ft_strcmp(cmd, RRA))
		do_rra(st_a, 0);
	else if (!ft_strcmp(cmd, RRB))
		do_rrb(st_b, 0);
	else if (!ft_strcmp(cmd, RRR))
		do_rrr(st_a, st_b, 0);
	else if (!ft_strcmp(cmd, SA))
		do_sa(st_a, 0);
	else if (!ft_strcmp(cmd, SB))
		do_sb(st_b, 0);
	else if (!ft_strcmp(cmd, SS))
		do_ss(st_a, st_b, 0);
	else if (!ft_strcmp(cmd, PA))
		do_pa(st_a, st_b, 0);
	else if (!ft_strcmp(cmd, PB))
		do_pb(st_a, st_b, 0);
	else
		return (1);
	return (0);
}
