/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <pifourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:19:25 by pifourni          #+#    #+#             */
/*   Updated: 2025/11/24 11:19:26 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../list.h"
#include <stdlib.h>

struct node	*new_node(char data)
{
	struct node	*n;

	n = malloc(sizeof(struct node));
	if (!n)
		return (NULL);
	n->data = data;
	n->next = NULL;
	n->prev = NULL;
	return (n);
}

void	push(struct node *n, struct node *stack)
{
	n->next = stack;
	stack->prev = n;
	n->prev = NULL;
	*stack = *n;
}

struct node	*pop(struct node *stack)
{
	struct node	*res;

	res = stack;
	stack = stack->next;
	res->next = NULL;
	res->prev = NULL;
	stack->prev = NULL;
	return (res);
}