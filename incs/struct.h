/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:34:27 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/15 18:58:54 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_command
{
	int	all;
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	rr;
	int	rrr;
}	t_command;

typedef struct s_node
{
	int				data;
	int				index;
	t_command		command;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_vec
{
	int	*arr;
	int	size;
}	t_vec;

typedef struct s_lis_info
{
	int	*dp;
	int	*lis;
	int	*prev;
	int	dp_size;
	int	lis_len;
	int	last;
}	t_lis_info;

#endif // STRUCT_H
