/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 16:52:34 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/11 22:58:21 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	arg_error(void)
{
	write(1, "Error\n", 6);
	return  (-1);
}

void	arg_error_exit(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}
