/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:24:35 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/06 14:39:22 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_binary_search(int *vec, int size, int key)
{
	int	ng;
	int	ok;
	int	mid;

	ng = 0;
	ok = size - 1;
	while (ng <= ok)
	{
		mid = ng + (ok - ng) / 2;
		if (vec[mid] == key)
			return (1);
		else if (vec[mid] > key)
			ok = mid - 1;
		else if (vec[mid] < key)
			ng = mid + 1;
	}
	return (0);
}

int	ft_lower_bound(int *vec, int size, int key)
{
	int	ng;
	int	ok;
	int	mid;

	ng = -1;
	ok = size;
	while (ok - ng > 1)
	{
		mid = ng + (ok - ng) / 2;
		if (vec[mid] >= key)
			ok = mid;
		else
			ng = mid;
	}
	return (ok);
}

int	ft_upper_bound(int *vec, int size, int key)
{
	int	ng;
	int	ok;
	int	mid;

	ng = -1;
	ok = size;
	while (ok - ng > 1)
	{
		mid = ng + (ok - ng) / 2;
		if (vec[mid] > key)
			ok = mid;
		else
			ng = mid;
	}
	return (ok);
}
