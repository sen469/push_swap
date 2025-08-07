/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:33:19 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/04 22:50:13 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	free_char2(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
}

void	free_lis(int *vec)
{
	if (!vec)
	{
		free(vec);
		vec = NULL;
	}
}
