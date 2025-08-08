/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 16:50:21 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/08 17:52:04 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static int	check_str_is_num(const char *str)
{
	int	i;

	i = 0;
	printf("str=%s=\n", str);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !ft_isspace(str[i]))
		{
			// printf("str_is_num valid=%c=\n", str[i]);
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
		if (str[i] != ' ' && !ft_isdigit(str[i]))
		{
			// printf("valid error\n");
			return (arg_error());
		}
		i++;
	}
	return (0);
}

// ac >=3 の時のチェック
// 数字の文字列の集合が渡されたとき
static int	check_args(int argc, char **argv)
{
	int	i;
	// int	flag;

	i = 1;
	// flag = 1;
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
		return (arg_error());
	}
	// 引数が2つの時
	else if (argc == 2 && arg2_check(argv[1]))
	{
		return (-1);
	}
	// 2以上の時
	else if (check_args(argc, argv))
	{
		printf("valid \n");
		return (-1);
		// return(check_args(argc, argv));
	}
	vec->arr = make_arr(argc, argv, &(vec->size));
	printf("valid.c size = %d\n", vec->size);
	return (check_arr(vec->arr, vec->size));
}
