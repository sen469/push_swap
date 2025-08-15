/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 17:38:19 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/15 19:01:12 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include <limits.h>

static long	check_overflow(long num, char c, int sign)
{
	long	digit;

	digit = c - '0';
	if (sign == 1)
	{
		if (num > (LONG_MAX - digit) / 10)
			return (LONG_MAX);
	}
	else
	{
		if (-num < (LONG_MIN + digit) / 10)
			return (LONG_MIN);
	}
	return (0);
}

long	ft_atol(const char *str)
{
	long	num;
	int		sign;
	long	overflow_flag;

	num = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		overflow_flag = check_overflow(num, *str, sign);
		if (overflow_flag != 0)
			return (overflow_flag);
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * sign);
}

/*
long	ft_atol(const char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (sign == 1)
		{
			if (num > (LONG_MAX - (*str - '0')) / 10)
				return (LONG_MAX);
		}
		else
		{
			if (-num < (LONG_MIN + (*str - '0')) / 10)
				return (LONG_MIN);
		}
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * sign);
}
*/
