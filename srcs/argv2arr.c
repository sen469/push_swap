/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv2arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:35:13 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/15 19:24:01 by ssawa            ###   ########.fr       */
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
		i++;
	return (i);
}

static int	convert_and_validate(int argc, char **str_arr, int *int_arr)
{
	int		i;
	long	tmp;

	i = 0;
	while (str_arr[i])
	{
		tmp = ft_atol(str_arr[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
		{
			free_arr(&int_arr);
			if (argc == 2)
				free_char_deg2(str_arr);
			error_exit();
		}
		int_arr[i] = (int)tmp;
		i++;
	}
	return (0);
}

int	*make_arr(int argc, char **argv, int *size)
{
	char	**str_arr;
	int		*int_arr;

	if (argc == 2)
		str_arr = ft_split(argv[1], ' ');
	else
		str_arr = &argv[1];
	if (!str_arr)
		exit(EXIT_FAILURE);
	*size = arr_size(str_arr);
	int_arr = ft_calloc(*size, sizeof(int));
	if (!int_arr)
	{
		if (argc == 2)
			free_char_deg2(str_arr);
		error_exit();
	}
	convert_and_validate(argc, str_arr, int_arr);
	if (argc == 2)
		free_char_deg2(str_arr);
	return (int_arr);
}

static int	has_duplicate(int num, const int *arr, int start_index, int size)
{
	int	j;

	j = start_index;
	while (j < size)
	{
		if (num == arr[j])
			return (1);
		j++;
	}
	return (0);
}

int	check_arr(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (has_duplicate(arr[i], arr, i + 1, size))
		{
			free_arr(&arr);
			error_exit();
		}
		i++;
	}
	return (0);
}
