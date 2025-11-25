/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <pifourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:04:20 by pifourni          #+#    #+#             */
/*   Updated: 2025/11/25 15:04:24 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../list.h"

static void	free_values(char **values)
{
	int	i;

	i = 0;
	while (values[i])
	{
		free(values[i]);
		i++;
	}
	free(values);
}

int	init_stacks(char **argv, struct s_node **stack_a)
{
	int		n;
	char	**values;

	n = 0;
	values = ft_split(argv[1], ' ');
	if (!values)
		return (-1);
	while (values[n])
	{
		struct s_node	*new;

		new = new_node(ft_atoi(values[n]));
		if (!new)
			return (-1);
		queue(new, *stack_a);
		n++;
	}
	free_values(values);
	return (n);
}