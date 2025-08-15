/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 11:30:25 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/15 17:56:40 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "struct.h"

int	get_stack_size(t_node *st)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = st->next;
	while (tmp != st)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
