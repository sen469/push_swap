/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:42:55 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/15 19:08:33 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static void	init_stack(t_node *st_a, t_node *st_b)
{
	st_a->prev = st_a;
	st_a->next = st_a;
	st_b->prev = st_b;
	st_b->next = st_b;
	st_a->index = INT_MAX;
}

int	main(int argc, char **argv)
{
	t_vec	vec;
	t_node	*st_a;
	t_node	*st_b;

	if (valid(argc, argv, &vec))
	{
		error_exit();
	}
	st_a = (t_node *)malloc(sizeof(t_node));
	st_b = (t_node *)malloc(sizeof(t_node));
	init_stack(st_a, st_b);
	if (init(&vec, st_a))
	{
		free_all(vec.arr, st_a, st_b);
		error_exit();
	}
	process(&vec, st_a, st_b);
	free_all(vec.arr, st_a, st_b);
}
