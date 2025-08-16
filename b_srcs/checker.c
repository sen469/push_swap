/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 22:16:04 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/16 16:35:05 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"
#include "struct.h"
#include "libft/get_next_line.h"

static void	init_stacks(t_node **st_a, t_node **st_b)
{
	*st_a = (t_node *)malloc(sizeof(t_node));
	*st_b = (t_node *)malloc(sizeof(t_node));
	if (!*st_a || !*st_b)
		error_exit();
	(*st_a)->prev = *st_a;
	(*st_a)->next = *st_a;
	(*st_b)->prev = *st_b;
	(*st_b)->next = *st_b;
}

static void	gnl_and_do_command(t_node *st_a, t_node *st_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		do_command_checker(st_a, st_b, line);
		free(line);
		line = get_next_line(0);
	}
	get_next_line(-1);
}

int	is_sorted_and_b_empty(t_node *st_a, t_node *st_b)
{
	t_node	*tmp;

	if (get_stack_size(st_b) != 0)
		return (0);
	if (get_stack_size(st_a) <= 1)
		return (1);
	tmp = st_a->next;
	while (tmp->next != st_a)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int	print_result(t_node *st_a, t_node *st_b)
{
	if (is_sorted_and_b_empty(st_a, st_b))
	{
		write(1, "OK\n", 3);
		return (1);
	}
	else
	{
		write(1, "KO\n", 3);
		return (0);
	}
}

int	main(int argc, char **argv)
{
	t_node	*st_a;
	t_node	*st_b;
	t_vec	vec;

	if (argc == 1)
		return (0);
	if (valid(argc, argv, &vec))
		error_exit();
	init_stacks(&st_a, &st_b);
	if (print_result(st_a, st_b))
	{
		free_stack(&st_a);
		free_stack(&st_b);
		return (0);
	}
	init(&vec, st_a);
	free(vec.arr);
	gnl_and_do_command(st_a, st_b);
	print_result(st_a, st_b);
	free_stack(&st_a);
	free_stack(&st_b);
	return (0);
}
