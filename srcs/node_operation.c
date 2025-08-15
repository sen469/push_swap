/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 22:36:26 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/15 19:55:56 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node_back(t_node *st, t_node *new_node)
{
	if (!st || !new_node)
		return ;
	new_node->prev = st->prev;
	st->prev->next = new_node;
	new_node->next = st;
	st->prev = new_node;
}

void	add_node_front(t_node *st, t_node *new_node)
{
	if (!st || !new_node)
		return ;
	new_node->next = st->next;
	st->next->prev = new_node;
	new_node->prev = st;
	st->next = new_node;
}

t_node	*create_new_node(int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->index = 0;
	new_node->command.all = 0;
	new_node->command.ra = 0;
	new_node->command.rra = 0;
	new_node->command.rb = 0;
	new_node->command.rrb = 0;
	new_node->command.rr = 0;
	new_node->command.rrr = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
