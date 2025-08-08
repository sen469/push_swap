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

	// ft_putstr_fd("init.c ok\n", 2);
	res = (int *)malloc(size * sizeof(int));
	if (!res)
	{
		// write(1, "error\n", 6);
		return (NULL);
	}
	// ft_putstr_fd("init.c ok\n", 2);
	i = -1;
	// printf("size = %d\n", size);
	while (++i < size)
	{
		res[i] = arr[i];
		// write(1, "count\n", 6);
	}
	i = size;
	// ft_putstr_fd("init.c ok\n", 2);
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
		// ft_putnbr_fd(i, 2);
		// write(2, "\n", 1);
	}
	return (res);
}

int	init(t_vec *vec, t_node *st_a, t_node *st_b)
{
	int		i;
	int		*sorted_vec;
	t_node	*new_node;

	// ft_putstr_fd("init.c ok\n", 2);
	sorted_vec = ft_bubble_sort(vec->arr, vec->size);
	if (!sorted_vec)
		return (-1);
	// ft_putstr_fd("init.c ok\n", 2);
	st_a = (t_node *)malloc(sizeof(t_node));
	st_b = (t_node *)malloc(sizeof(t_node));
	st_b->prev = st_b;
	st_b->next = st_b;
	// ft_putstr_fd("init.c ok\n", 2);
	i = 0;
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
	// ft_putstr_fd("init.c ok\n", 2);
	return (0);
}
