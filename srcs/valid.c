/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 16:50:21 by ssawa             #+#    #+#             */
/*   Updated: 2025/07/18 11:02:34 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

// ac == 2のときの文字列チェック
static int	arg2_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && ft_isdigit(str[i]))
		{
			return (arg_error());
		}
	}
	return (0);
}

// ac >=3 の時のチェック
static int	check_args(int ac, char **argv)
{
	int	i;
	int	flag;

	i = 1;
	flag = 1;
	while (i < ac)
	{
		if (argv[i])
		{

		}
	}
}

int	valid(int ac, char **str, t_node **node)
{
	int	i;

	i = 0;
	// 引数の個数チェック
	if (ac == 1)
	{
		return (arg_error());
	}
	// 引数が2つの時
	else if (ac == 2)
	{
		return (arg2_check(str[1]));
	}
	// それ以外
	else
	{

	}
	return (0);
}
