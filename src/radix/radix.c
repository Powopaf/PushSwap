/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <pifourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:32:28 by pifourni          #+#    #+#             */
/*   Updated: 2025/11/26 16:32:32 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "radix.h"

static int	get_min(t_list *stack)
{
	int	min;

	min = *(int *)stack->content;
	stack = stack->next;
	while (stack)
	{
		if (*(int *)stack->content < min)
			min = *(int *)stack->content;
		stack = stack->next;
	}
	return (min);
}

static int	norm(t_list *stack, int min)
{
	long	num;

	num = *(int *)stack->content - min;
	stack = stack->next;
	while (stack)
	{
		if ((*(int *)stack->content - min) < num)
			num = *(int *)stack->content - min;
		stack = stack->next;
	}
	return (num);
}

static int	get_max_bits(t_list *stack)
{
	int	max_bits;
	size_t	max_num;

	max_bits = 0;
	max_num = norm(stack, get_min(stack));
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	sort(t_list **stack_a, t_list **stack_b, size_t size)
{
	int		maxBits;
	int		i;
	long	num;
	int		min;
	size_t	j;

	maxBits = get_max_bits(*stack_a);
	i = 0;
	min = get_min(*stack_a);
	while (i < maxBits)
	{
		j = 0;
		while (j < size)
		{
			num = (long)(*stack_a)->content - (long)min;
			if (((num >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		j++;
	}
	while (*stack_b)
		pa(stack_a, stack_b);
	i++;
}