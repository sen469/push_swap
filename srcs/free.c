/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:33:19 by ssawa             #+#    #+#             */
/*   Updated: 2025/07/17 15:04:04 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include "struct.h"

void	node_free(t_node **node)
{
	t_node *nxt;

	if (*node)
	{
		while (*node)
		{
			nxt = (*node)->next;
			free(*node);
			*node = nxt;
		}
	}
}
