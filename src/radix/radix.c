/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <pifourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:32:28 by pifourni          #+#    #+#             */
/*   Updated: 2025/11/28 10:28:31 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "radix.h"

static int	*create_array(t_list *stack, size_t size)
{
	int		*array;
	size_t	i;
	t_list	*current;

	array = malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	i = 0;
	current = stack;
	while (current)
	{
		array[i] = ((t_data *)current->content)->num;
		current = current->next;
		i++;
	}
	return (array);
}

static void	sort_array(int *array, size_t size)
{
	size_t	i;
	size_t	j;
	int		temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static void	assign_indices(t_list *stack, int *array, size_t size)
{
	t_list	*current;
	size_t	i;

	sort_array(array, size);
	current = stack;
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (((t_data *)current->content)->num == array[i])
			{
				((t_data *)current->content)->index = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
	free(array);
}

static int	get_max_bits(t_list *stack)
{
	int		max_index;
	int		bits;
	t_list	*current;

	max_index = 0;
	current = stack;
	while (current)
	{
		if (((t_data *)current->content)->index > max_index)
			max_index = ((t_data *)current->content)->index;
		current = current->next;
	}
	bits = 0;
	while ((max_index >> bits) != 0)
		bits++;
	return (bits);
}

void	sort(t_list **stack_a, t_list **stack_b, size_t size)
{
	int		max_bits;
	int		i;
	size_t	j;

	assign_indices(*stack_a, create_array(*stack_a, size), size);
	max_bits = get_max_bits(*stack_a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((t_data *)(*stack_a)->content)->index >> i) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		i++;
		while (*stack_b)
			pa(stack_a, stack_b);
	}
}
