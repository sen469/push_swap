/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:47:13 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/10 20:29:13 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include "struct.h"
#include <limits.h>

// ノードのメンバ変数を出力する関数
void	print_node(t_node *node)
{
	printf("data, index, all\t%d , %d, %d", node->data, node->index, node->command.all);
	printf("\tra, rb, rr = \t%d , %d, %d", node->command.ra, node->command.rb, node->command.rr);
	printf("\trra, rrb, rrr = \t%d , %d, %d\n", node->command.rra, node->command.rrb, node->command.rrr);
}

// スタックAのLIS以外の要素をスタックBに移す関数
void	make_stack_b(t_node *st_a, t_node *st_b, t_vec *lis)
{
	int	st_a_size;
	int	i;

	i = 0;
	st_a_size = stack_size(st_a);
	while (i < st_a_size)
	{
		if (!ft_binary_search(lis->arr, lis->size, st_a->next->data))
		{
			do_pb(st_a, st_b);
		}
		else
		{
			do_ra(st_a);
		}
		i++;
	}
}

// スタックBの各ノードが一番上にするにはどのくらいコストがかかるのか
// という関数
void	cost_of_top_b(t_node *st_b)
{
	int		cost_r;
	int		st_size_b;
	t_node	*tmp;

	st_size_b = stack_size(st_b);
	tmp = st_b->next;
	cost_r = 0;
	while (tmp != st_b)
	{
		tmp->command.rb = cost_r;
		tmp->command.rrb = st_size_b - cost_r;
		cost_r++;
		tmp = tmp->next;
	}
}

// スタックBから最小コストとなるノードはどれかを選ぶ関数
t_node *chose_min_cost(t_node *st)
{
	t_node		*tmp;
	t_command	cmd;
	int			mn;
	t_node		*ret;

	mn = INT_MAX;
	tmp = st->next;
	ret = NULL;
	while (tmp != st)
	{
		// printf("before\n");
		// print_node(tmp);
		sum_cost(tmp);
		cmd = tmp->command;
		// printf("after\n");
		// print_node(tmp);
		if (cmd.all < mn)
		{
			mn = cmd.all;
			ret = tmp;
		}
		tmp = tmp->next;
	}
	return (ret);
}

/*
int	min_index(t_node *st)
{
	t_node	*tmp;
	int		mn;

	tmp =st->next;
	mn = INT_MAX;
	while (tmp != st)
	{
		mn = ft_min(mn, tmp->index);
		tmp = tmp->next;
	}
	// printf("process.c 100 mn = %d\n", mn);
	return (mn);
}
*/

// スタックAの最少インデックスは上から何番目かを調べる関数
int	get_min_index(t_node *st)
{
	t_node	*tmp;
	int		mn_index;
	int		cost;
	int		res;

	tmp = st->next;
	mn_index = INT_MAX;
	cost = 0;
	while (tmp != st)
	{
		if (tmp->index < mn_index)
		{
			res = cost;
			mn_index = tmp->index;
		}
		cost++;
		tmp = tmp->next;
	}
	// printf("process.c 121 res = %d\n", res);
	return (res);
}

// スタックAの正しい場所に入れるまでに必要な手数を計算する関数
void	cost_of_b2a(t_node *st_a, t_node *st_b)
{
	int		st_size_a;
	int		cost_r;
	t_node	*tmp_a;
	t_node	*tmp_b;
	int		flag = 1;

	st_size_a = stack_size(st_a);
	tmp_b = st_b->next;
	while (tmp_b != st_b)
	{
		cost_r = 0;
		tmp_a = st_a->next;
		flag = 1;
		while (tmp_a != st_a)
		{
			if (tmp_a->prev->index < tmp_b->index && tmp_b->index < tmp_a->index)
			{
				tmp_b->command.ra = cost_r;
				tmp_b->command.rra = st_size_a - cost_r;
				flag = 0;
				break ;
			}
			tmp_a = tmp_a->next;
			cost_r++;
		}
		if (st_a->prev->index < tmp_b->index && tmp_b->index < st_a->next->index)
		{
			tmp_b->command.ra = 0;
			tmp_b->command.rra = st_size_a;
		}
		else if (flag)
		{
			cost_r = get_min_index(st_a);
			tmp_b->command.ra = cost_r;
			tmp_b->command.rra = st_size_a - cost_r;
		}
		tmp_b = tmp_b->next;
	}
}

// スタックBから要素を一つ移すたびに
// スタックBの各ノードのcommandメンバを初期化する必要がある
void	init_node_command(t_node *st)
{
	t_node	*tmp;

	// st->index = INT_MAX / 2;
	// st->index = -1;
	tmp = st->next;
	while (tmp != st)
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


// PROCESS()
void	process(t_vec *vec, t_node *st_a, t_node *st_b)
{
	t_vec	lis;
	t_node	*min_cost_node;
	int		st_a_size;
	t_node *tmp;
	int		cst;

	process_lis(vec, &lis);
	make_stack_b(st_a, st_b, &lis);
	free_arr(lis.arr);
	free_arr(vec->arr);
	while (st_b->next != st_b)
	{
		tmp = st_a->next;
		/*
		while (tmp != st_a)
		{
			// printf("process.c 191 st_a.data = %d, index = %d\n", tmp->data, tmp->index);
			tmp = tmp->next;
		}
		*/
		// printf("=======================================================================================\n");
		cost_of_top_b(st_b);
		cost_of_b2a(st_a, st_b);
		min_cost_node = chose_min_cost(st_b);
		do_command(min_cost_node, st_a, st_b);
		do_pa(st_a, st_b);
		init_node_command(st_b);
		/*
		while (tmp != st_a)
		{
			printf("process.c 191 tmp.data = %d\n", tmp->data);
			tmp = tmp->next;
		}
		*/
	}
	st_a_size = stack_size(st_a);
	tmp = st_a->next;
	cst = 0;
	while (tmp != st_a)
	{
		if (tmp->index == 1)
		{
			break ;
		}
		cst++;
		tmp = tmp->next;
	}
	cst--;
	if (cst < st_a_size - cst)
	{
		while (cst--)
		{
			do_ra(st_a);
		}
	}
	else
	{
		while (st_a_size - cst++)
		{
			do_rra(st_a);
		}
	}
}
