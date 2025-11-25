/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <pifourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:19:25 by pifourni          #+#    #+#             */
/*   Updated: 2025/11/24 17:53:00 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../list.h"
#include <stdlib.h>

struct s_node	*new_node(int data)
{
	struct s_node	*n;

	n = malloc(sizeof(struct s_node));
	if (!n)
		return (NULL);
	n->data = data;
	n->next = NULL;
	n->prev = NULL;
	return (n);
}

void	queue(struct s_node *n, struct s_node *stack)
{
	n->next = stack;
	stack->prev = n;
	n->prev = NULL;
	*stack = *n;
}

struct s_node	*dequeue(struct s_node *stack)
{
	struct s_node	*res;

	res = stack;
	stack = stack->next;
	res->next = NULL;
	res->prev = NULL;
	stack->prev = NULL;
	return (res);
}

int	is_empty(struct s_node *stack)
{
	return (stack == NULL);
}

void	free_stack(struct s_node *stack)
{
	struct s_node	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
	stack = NULL;
}
