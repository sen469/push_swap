/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:47:13 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/08 11:40:36 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft/libft.h"
#include "libft/libft.h"
#include "push_swap.h"
#include "struct.h"

// スタックAのLIS以外の要素をスタックBに移す関数
void	make_stack_b(t_node *st_a, t_node *st_b, t_vec *lis)
{
	t_node	*tmp;

	tmp = st_a->next;
	while (tmp != st_a)
	{
		if (ft_binary_search(lis->arr, lis->size, tmp->data))
			do_pa(st_a, st_b);
		tmp = tmp->next;
	}
}

void	cost_of_top_b(t_node *st_b)
{
	int	cst_r;
	int	st_size_b;
	int	st_size_a;
	t_node	*tmp;

	st_size_b = stack_size(st_b);
	tmp = st_b->next;
	while (tmp != st_b)
	{
		if (cst_r < st_size_b - cst_r)
		{
			tmp->command.rb = cst_r;
		}
		else
		{
			tmp->command.rrb = st_size_b - cst_r;
		}
		cst_r++;
		tmp = tmp->next;
	}
}

t_node *min_cost(t_node *st)
{
	t_node	*tmp;

	tmp = st->next;
}

void	process(t_node *st_a, t_node *st_b, t_vec *vec)
{
	t_vec	lis;

	process_lis(vec, &lis);
	make_stack_b(st_a, st_b, &lis);
	// cost_of_top(st_b);
	/*
	write(1, "process\n", 9);
	printf("lis.size = %d\n", lis.size);
	for (int i = 0; i < lis.size; i++)
	{
		printf("%d\n", lis.arr[i]);
	}
	*/
}
