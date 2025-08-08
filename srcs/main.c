/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:42:55 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/06 22:39:48 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_vec		vec;
	t_node	st_a;
	t_node	st_b;

	// 入力の引数が正しいかどうかをチェックする
	// VALIDIDATE()
	ft_putstr_fd("main ok\n", 2);
	if (valid(argc, argv, &vec))
	{
		printf("error\n");
		return (1);
	}
	// 連結リストを作成する
	// INITIALIZE()
	ft_putstr_fd("main ok\n", 2);
	if (init(&vec, &st_a, &st_b))
	{
		return (1);
	}
	ft_putstr_fd("main ok\n", 2);
	process(&vec);
	// PROCESS()
	// EXIT()

}
