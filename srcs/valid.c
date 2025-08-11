/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 16:50:21 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/11 22:49:20 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>

static int	check_str_is_num(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !ft_isspace(str[i]))
		{
			return (-1);
		}
		i++;
	}
	return (0);
}

// ac == 2のときの文字列チェック
// ""で数字の集合が1つの文字列になっているとき
static int	arg2_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]) && !ft_isdigit(str[i]))
		{
			return (arg_error());
		}
		i++;
	}
	return (0);
}

// ac >=3 の時のチェック
// 数字の文字列の集合が渡されたとき
static int	args_check(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (check_str_is_num(argv[i]))
		{
			return (-1);
		}
		i++;
	}
	return (0);
}

int	valid(int argc, char **argv, t_vec *vec)
{
	// int	i;

	// i = 0;
	// 引数の個数チェック
	if (argc == 1)
	{
		exit(EXIT_SUCCESS);
	}
	// 引数が2つの時
	else if (argc == 2 && arg2_check(argv[1]))
	{
		return (-1);
	}
	// 2以上の時
	else if (args_check(argc, argv))
	{
		return (-1);
	}
	vec->arr = make_arr(argc, argv, &(vec->size));
	return (check_arr(vec->arr, vec->size));
}
