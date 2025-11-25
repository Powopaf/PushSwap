/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <pifourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 10:34:53 by pifourni          #+#    #+#             */
/*   Updated: 2025/11/24 17:17:52 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int	main(int argc, char **argv)
{
	struct s_node	*stack_a;
	struct s_node	*stack_b;
	int				n;
	
	if (argc < 2)
		return (0);
	n = 0; // TODO: initialize stack_a with input values and return the lenghth
	stack_b = NULL;
	if (n <= 3)
		return (1); // TODO: call sorting function for 3 elts
	else if (n <= 5)
		return (2); // TODO: call sorting function for 5 elts
	// TODO: Normalize
	// TODO: Radix sort
	return (0);
}
