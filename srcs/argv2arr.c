/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv2arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:35:13 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/11 23:06:00 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>

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

static void _free(char **str, int *arr)
{
	free_char_deg2(str);
	free_arr(arr);
}

// ダブりチェック
int	*make_arr(int argc, char **argv, int *size)
{
	char	**str_arr;
	int		*int_arr;
	int		i;
	long	tmp;

	if (argc == 2)
		str_arr = ft_split(argv[1], ' ');
	else
		str_arr = &argv[1];
	if (!str_arr)
		exit(EXIT_FAILURE);
	*size = arr_size(str_arr);
	int_arr = ft_calloc(*size, sizeof(int));
	i = 0;
	while (str_arr[i])
	{
		tmp = ft_atol(str_arr[i]);
		if (INT_MAX < tmp || INT_MIN > tmp)
		{
			_free(str_arr, int_arr);
			arg_error_exit();
		}
		int_arr[i] = ft_atoi(str_arr[i]);
		i++;
	}
	if (argc == 2)
	{
		free_char_deg2(str_arr);
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
				free_arr(arr);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	return (0);
}
