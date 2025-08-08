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
	int	cost_r;
	int	st_size_b;
	t_node	*tmp;

	st_size_b = stack_size(st_b);
	tmp = st_b->next;
	cost_r = 0;
	while (tmp != st_b)
	{
		if (cost_r < st_size_b - cost_r)
		{
			tmp->command.rb = cost_r;
		}
		else
		{
			tmp->command.rrb = st_size_b - cost_r;
		}
		cost_r++;
		tmp = tmp->next;
	}
}

t_node *min_cost(t_node *st)
{
	t_node	*tmp;
	t_command	cmd;
	int			mn;
	t_node	*ret;

	mn = INT_MAX;
	tmp = st->next;
	ret = NULL;
	while (tmp != st)
	{
		cmd = tmp->command;
		cmd.all = cmd.ra + cmd.rb + cmd.rr + cmd.rra + cmd.rrb + cmd.rrr;
		if (cmd.all < mn)
		{
			mn = cmd.all;
			ret = tmp;
		}
		tmp = tmp->next;
	}
	return (ret);
}

// スタックAの正しい場所に入れるまでに必要な手数を計算する関数
void	cost_of_b2a(t_node *st_a, t_node *st_b)
{
	int	st_size_a;
	int	cost_r;
	t_node	*tmp_a;
	t_node	*tmp_b;

	st_size_a = stack_size(st_a);
	tmp_b = st_b->next;
	cost_r = 0;
	while (tmp_b != st_b)
	{
		tmp_a = st_a->next;
		while (tmp_a != st_a)
		{
			if (tmp_a->prev->index < tmp_b->index && tmp_b->index < tmp_a->index)
			{
				if (cost_r < st_size_a - cost_r)
				{
					tmp_b->command.ra = cost_r;
				}
				else
				{
					tmp_b->command.rra = st_size_a - cost_r;
				}
			}
			tmp_a = tmp_a->next;
		}
		cost_r++;
		tmp_b = tmp_b->next;
	}
}

void	init_node_command(t_node *st)
{
	t_node	*tmp;

	tmp = st->next;
	while (tmp->next != st)
	{
		tmp->command.rra = 0;
		tmp->command.ra = 0;
		tmp->command.rrb = 0;
		tmp->command.rb = 0;
		tmp->command.rr = 0;
		tmp->command.rrr = 0;
		tmp->command.all = 0;
		tmp = tmp->next;
	}
}

void	process(t_vec *vec, t_node *st_a, t_node *st_b)
{
	t_vec	lis;
	t_node	*min_cost_node;

	process_lis(vec, &lis);
	make_stack_b(st_a, st_b, &lis);
	// スタックBの各ノードがtopとなるコストを求める
	// スタックBをの各ノードがスタックAの正しいノードに移動するまでのコストを求める
	// 最小コストとなるノードを求める
	// そのノードを移動する
	// これをスタックBが空になるまで実行する
	while (st_b->next != st_b->prev)
	{
		cost_of_top_b(st_b);
		cost_of_b2a(st_a, st_b);
		min_cost_node = min_cost(st_b);
		do_command(min_cost_node, st_a, st_b);
		init_node_command(st_b);
	}
}
