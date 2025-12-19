/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <pifourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 10:34:53 by pifourni          #+#    #+#             */
/*   Updated: 2025/12/15 14:47:33 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "src/parsing/parse.h"
#include "src/error/error.h"
#include "src/radix/radix.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	size_t	size;

	size = 0;
	stack_a = parser(argc, argv, &size);
	if (!stack_a)
		return (error_message("\x1b[31mError while parsing arguments\x1b[0m"));
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
