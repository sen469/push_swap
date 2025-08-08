/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 17:38:19 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/08 17:47:13 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include <limits.h>

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
		if (num > (LONG_MAX - (*str - '0')) / 10)
		{
			if (sign == 1)
				return (LONG_MAX);
			else
				LONG_MIN;
		}
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * sign);
}

