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
#include "../error/error.h"

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

void	free_split(char **split)
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

static int	is_many(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

static int	add(char **split, t_list **stack, size_t j, size_t *i)
{
	t_data	*data;
	int		num;

	if (!check_num(split[j]))
		return (0);
	num = ft_atoi(split[j]);
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->index = 0;
	data->num = num;
	ft_lstadd_front(stack, ft_lstnew(data));
	(*i)++;
	return (1);
}

t_list	*parser(int argc, char **argv, size_t *k)
{
	int		i;
	size_t	j;
	t_list	*stack;
	char	**split;

	i = argc;
	stack = NULL;
	while (--i > 0)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (error_parsing(NULL, stack));
		j = is_many(split);
		while (--j != 0)
		{
			if (!add(split, &stack, j, k))
				return (error_parsing(split, stack));
		}
		if (!add(split, &stack, j, k))
			return (error_parsing(split, stack));
		free_split(split);
	}
	return (stack);
}
