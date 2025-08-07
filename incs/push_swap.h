/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:48:11 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/06 22:41:07 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

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
t_vec	process_lis(t_vec *vec);
void	add_node_back(t_node *st, t_node *new_node);
void	add_node_front(t_node *st, t_node *new_node);
t_node	*create_new_node(int data);

#endif
