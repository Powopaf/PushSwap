/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <pifourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 10:34:53 by pifourni          #+#    #+#             */
/*   Updated: 2025/11/26 16:42:01 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "src/parsing/parse.h"
#include "src/error/error.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = parser(argc, argv);
	if (!stack_a)
		return (error_message("\x1b[31mError while parsing arguments\x1b[0m"));
	stack_b = NULL;
	t_list *c = stack_a;
	while (c)
	{
		printf("%d\n", *(int *)c->content);
		c = c->next;
	}
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return (0);
}
