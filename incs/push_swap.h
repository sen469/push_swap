/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:48:11 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/08 11:46:15 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
# include "struct.h"

int		arg_error(void);
int		valid(int argc, char **str, t_vec *vec);
void	node_free(t_node **node);
int		*make_arr(int argc, char **argv, int *size);
int		check_arr(int *arr, int size);
void	free_char2(char **str);
int		init(t_vec *vec, t_node *st_a, t_node *st_b);
void	free_lis(int *vec);
void	process_lis(t_vec *vec, t_vec *lis);
void	add_node_back(t_node *st, t_node *new_node);
void	add_node_front(t_node *st, t_node *new_node);
t_node	*create_new_node(int data);
void	do_pa(t_node *st_a, t_node *st_b);
void	do_pb(t_node *st_a, t_node *st_b);
void	do_ra(t_node *st_a);
void	do_rb(t_node *st_b);
void	do_rr(t_node *st_a, t_node *st_b);
void	do_rra(t_node *st_a);
void	do_rrb(t_node *st_b);
void	do_rrr(t_node *st_a, t_node *st_b);
void	do_sa(t_node *st_a);
void	do_sb(t_node *st_b);
void	do_ss(t_node *st_a, t_node *st_b);
void	do_command(t_node *node, t_node *st_a, t_node *st_b);
void	process(t_vec *vec, t_node *st_a, t_node *st_b);
int		stack_size(t_node *st);

#endif
