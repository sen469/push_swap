/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:48:11 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/16 16:06:46 by ssawa            ###   ########.fr       */
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
void	free_char_deg2(char **str);
int		init(t_vec *vec, t_node *st_a);
void	free_arr(int **vec);
void	process_lis(t_vec *vec, t_vec *lis);
void	add_node_back(t_node *st, t_node *new_node);
void	add_node_front(t_node *st, t_node *new_node);
t_node	*create_new_node(int data);
void	do_pa(t_node *st_a, t_node *st_b, int flag);
void	do_pb(t_node *st_a, t_node *st_b, int flag);
void	do_ra(t_node *st_a, int flag);
void	do_rb(t_node *st_b, int flag);
void	do_rr(t_node *st_a, t_node *st_b, int flag);
void	do_rra(t_node *st_a, int flag);
void	do_rrb(t_node *st_b, int flag);
void	do_rrr(t_node *st_a, t_node *st_b, int flag);
void	do_sa(t_node *st_a, int flag);
void	do_sb(t_node *st_b, int flag);
void	do_ss(t_node *st_a, t_node *st_b, int flag);
void	do_command(t_node *node, t_node *st_a, t_node *st_b);
void	process(t_vec *vec, t_node *st_a, t_node *st_b);
int		get_stack_size(t_node *st);
void	sum_cost(t_node *tmp);
void	free_stack(t_node **st);
void	free_all(int *arr, t_node *st_a, t_node *st_b);
void	error_exit(void);
void	process_sub(int size, t_node *st_a, t_node *st_b);
void	move_target_to_top(t_node *st_a, int target_index);
void	init_node_command(t_node *st);
void	make_stack_b(t_node *st_a, t_node *st_b, t_vec *lis);
void	cost_of_top_b(t_node *st_b);
t_node	*chose_min_cost(t_node *st);
int		get_min_index(t_node *st);
int		is_sorted(t_node *st_a);

#endif
