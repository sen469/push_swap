/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:35:13 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/04 18:15:02 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	arr_size(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

// ダブりチェック
int	*make_arr(int argc, char **argv, int *size)
{
	char	**str_arr;
	int	*int_arr;
	int		i;

	if (argc == 2)
		str_arr = ft_split(argv[1], ' ');
	else
		str_arr = &argv[1];
	// arr_size関数がおかしい
	// 文字列の個数を数える関数
	*size = arr_size(str_arr);
	// printf("arr_checks.c size = %d\n", *size);
	int_arr = ft_calloc(*size, sizeof(int));
	i = 0;
	while (str_arr[i])
	{
		int_arr[i] = ft_atoi(str_arr[i]);
		i++;
	}
	if (argc == 2)
	{
		free_char2(str_arr);
	}
	return (int_arr);
}

int	check_arr(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
			{
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
