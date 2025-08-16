/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:04:47 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/15 19:08:22 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include "struct.h"

static int	init_lis(t_lis_info *tmp, int size)
{
	int	i;

	tmp->dp = (int *)malloc((size + 1) * sizeof(int));
	tmp->prev = (int *)malloc(size * sizeof(int));
	if (!tmp->dp || !tmp->prev)
	{
		tmp->dp_size = -1;
		return (-1);
	}
	i = 0;
	while (i < size + 1)
	{
		tmp->dp[i] = INT_MAX;
		i++;
	}
	i = 0;
	while (i < size)
	{
		tmp->prev[i] = INT_MAX;
		i++;
	}
	tmp->dp[0] = INT_MIN;
	tmp->dp_size = size + 1;
	return (0);
}

/*
static int	init_lis(t_lis_info *tmp, int size)
{
	int	i;

	tmp->dp = (int *)malloc((size + 1) * sizeof(int));
	tmp->prev = (int *)malloc(size * sizeof(int));
	if (!tmp->dp || !tmp->prev)
	{
		tmp->dp_size = -1;
		return (-1);
	}
	i = 0;
	while (i < size)
	{
		tmp->dp[i] = INT_MAX;
		tmp->prev[i] = INT_MAX;
		i++;
	}
	tmp->dp[0] = INT_MIN;
	tmp->dp_size = size + 1;
	return (0);
}
*/

static void	build_dp_table(t_vec *vec, t_lis_info *tmp)
{
	int	i;
	int	idx;

	i = 0;
	while (i < vec->size)
	{
		idx = ft_lower_bound(tmp->dp, tmp->dp_size, vec->arr[i]);
		tmp->dp[idx] = vec->arr[i];
		tmp->prev[i] = tmp->dp[idx - 1];
		i++;
	}
}

static void	restore_lis(t_lis_info *tmp, t_vec *vec)
{
	int	x;
	int	i;
	int	j;

	i = vec->size - 1;
	x = tmp->last;
	j = tmp->lis_len - 1;
	tmp->lis = (int *)malloc(tmp->lis_len * sizeof(int));
	if (!tmp->lis)
		return ;
	while (i >= 0)
	{
		if (x == vec->arr[i])
		{
			tmp->lis[j--] = x;
			x = tmp->prev[i];
		}
		i--;
	}
}

static int	get_lis_len(int *dp, int *last, int dp_size)
{
	int	i;
	int	len;

	i = 1;
	len = 0;
	while (i < dp_size && dp[i] != INT_MAX)
	{
		len++;
		(*last) = dp[i];
		i++;
	}
	return (len);
}

void	process_lis(t_vec *vec, t_vec *lis)
{
	t_lis_info	tmp;

	lis->arr = NULL;
	lis->size = 0;
	if (init_lis(&tmp, vec->size))
		return ;
	build_dp_table(vec, &tmp);
	tmp.lis_len = get_lis_len(tmp.dp, &tmp.last, tmp.dp_size);
	lis->size = tmp.lis_len;
	restore_lis(&tmp, vec);
	lis->arr = tmp.lis;
	free(tmp.prev);
	free(tmp.dp);
}
