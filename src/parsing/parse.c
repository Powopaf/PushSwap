/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <pifourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:47:13 by pifourni          #+#    #+#             */
/*   Updated: 2025/11/26 14:47:18 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	check_num(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	free_split(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

t_list	*parser(int argc, char **argv)
{
	int	i;
	size_t	j;
	t_list	*stack;
	char	**split;

	i = argc - 1;
	stack = NULL;
	while (i > 1)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (NULL);
		j = 0;
		while (split[j])
		{
			if (!check_num(split[j]))
				return (NULL);
			ft_lstadd_front(&stack, ft_lstnew(ft_atoi(split[j])));
			j++;
		}
		free_split(split);
		i--;
	}
	return (stack);
}