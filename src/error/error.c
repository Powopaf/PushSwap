/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <pifourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:25:25 by pifourni          #+#    #+#             */
/*   Updated: 2025/12/30 11:00:22 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

int	error_message(char *msg, t_list *a)
{
	ft_putendl_fd(msg, 2);
	if (a)
		ft_lstclear(&a, free);
	return (1);
}

t_list	*error_parsing(char **split, t_list *stack)
{
	if (split)
		free_split(split);
	if (stack)
		ft_lstclear(&stack, free);
	return (NULL);
}
