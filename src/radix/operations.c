/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <pifourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:11:58 by pifourni          #+#    #+#             */
/*   Updated: 2025/11/27 14:12:02 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "radix.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (!stack_b || !*stack_b)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
	ft_putendl_fd("pa", 1);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (!stack_a || !*stack_a)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
	ft_putendl_fd("pb", 1);
}

void	ra(t_list **stack_a)
{
	t_list	*temp;
	t_list	*c;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = NULL;
	c = *stack_a;
	while (c->next != NULL)
		c = c->next;
	c->next = temp;
	ft_putendl_fd("ra", 1);
}
