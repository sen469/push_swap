/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:22:42 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/06 22:49:42 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include "struct.h"


int	*ft_bubble_sort(int *arr, int size)
{
	int	*res;
	int	i;
	int	j;

	res = (int *)malloc(size * sizeof(int));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < size)
		res[i] = arr[i];
	i = size;
	while (--i >= 0)
	{
		j = -1;
		while (++j < i)
		{
			if (res[j] > res[j + 1])
			{
				res[j] ^= res[j + 1];
				res[j + 1] ^= res[j];
				res[j] ^= res[j + 1];
			}
		}
	}
	return (res);
}

int	init(t_vec *vec, t_node *st_a, t_node *st_b)
{
	int		i;
	int		*sorted_vec;
	t_node	*new_node;

	sorted_vec = ft_bubble_sort(vec->arr, vec->size);
	if (!sorted_vec)
		return (-1);
	st_a = (t_node *)malloc(sizeof(t_node));
	st_b = (t_node *)malloc(sizeof(t_node));
	while (i < vec->size)
	{
		new_node = create_new_node(vec->arr[i]);
		new_node->data = vec->arr[i];
		new_node->index = ft_lower_bound(sorted_vec, vec->size, vec->arr[i]);
		if (!new_node)
			return (-1);
		add_node_back(st_a, new_node);
		i++;
	}
	return (0);
}
