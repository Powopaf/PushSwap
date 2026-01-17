/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <pifourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 10:34:53 by pifourni          #+#    #+#             */
/*   Updated: 2026/01/17 16:45:56 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "src/parsing/parse.h"
#include "src/error/error.h"
#include "src/radix/radix.h"
#include <stdio.h>

int	is_sort(t_list *a);
int	is_twice(t_list *a);

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	size_t	size;

	size = 0;
	stack_a = parser(argc, argv, &size);
	if (!stack_a)
		return (error_message("Error", stack_a));
	if (!is_twice(stack_a))
		return (error_message("Error", stack_a));
	if (!is_sort(stack_a))
		return (ft_lstclear(&stack_a, free), 0);
	stack_b = NULL;
	if (size <= 2)
		two_sort(&stack_a);
	else if (size == 3)
		three_sort(&stack_a);
	else if (size <= 5)
		small_sort(&stack_a, &stack_b);
	else
		sort(&stack_a, &stack_b, size);
	ft_lstclear(&stack_a, delete_data);
	ft_lstclear(&stack_b, delete_data);
	return (0);
}

int	is_twice(t_list *a)
{
	t_list	*prev;
	int		n;
	t_list	*curr;

	n = ((t_data *)a->content)->num;
	prev = a;
	while (prev->next)
	{
		curr = prev->next;
		while (curr)
		{
			if (((t_data *)curr->content)->num == n)
				return (0);
			curr = curr->next;
		}
		prev = prev->next;
		n = ((t_data *)prev->content)->num;
	}
	return (1);
}

int	is_sort(t_list *a)
{
	t_list	*temp;
	int		last;
	t_list	*curr;

	temp = a;
	last = ((t_data *)temp->content)->num;
	while (temp->next)
	{
		curr = temp->next;
		while (curr)
		{
			if (last > ((t_data *)curr->content)->num)
				return (1);
			curr = curr->next;
		}
		temp = temp->next;
		last = ((t_data *)temp->content)->num;
	}
	return (0);
}
