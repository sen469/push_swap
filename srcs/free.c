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

void	free_stack(t_node *st)
{
	t_node	*tmp;
	t_node	*next;

	if (!st)
		return ;
	tmp = st->next;
	while (tmp != st)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(st);
}

void	free_char_deg2(char **str)
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

void	free_arr(int *vec)
{
	if (vec)
	{
		free(vec);
		vec = NULL;
	}
}

void	free_all(int *arr, t_node *st_a, t_node *st_b)
{
	free_arr(arr);
	free_stack(st_a);
	free_stack(st_b);
}
