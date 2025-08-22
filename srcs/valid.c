/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 16:50:21 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/15 19:16:34 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>

static int	check_str_is_num(const char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (str[i] && ft_isspace(str[i]))
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		flag = 0;
		i++;
	}
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (flag)
		return (1);
	else if (str[i] == '\0')
		return (0);
	else
		return (1);
}

static int	arg2_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]) && !ft_isdigit(str[i]) && str[i] != '-')
		{
			return (-1);
		}
		i++;
	}
	return (0);
}

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
	if (argc == 1)
	{
		exit(EXIT_SUCCESS);
	}
	else if (argc == 2 && arg2_check(argv[1]))
	{
		return (-1);
	}
	else if (args_check(argc, argv))
	{
		return (-1);
	}
	vec->arr = make_arr(argc, argv, &(vec->size));
	return (check_arr(vec->arr, vec->size));
}
