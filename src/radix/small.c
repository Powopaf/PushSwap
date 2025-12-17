/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <pifourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:33:40 by pifourni          #+#    #+#             */
/*   Updated: 2025/12/16 16:33:43 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "radix.h"

void	two_sort(t_list **a)
{
	if (((t_data*)(*a)->content)->num > ((t_data*)(*a)->next->content)->num)
		sa(a);
}

void	three_sort(t_list **a)
{
	int	first;
	int	second;
	int	third;

	first = ((t_data*)(*a)->content)->num;
	second = ((t_data*)(*a)->next->content)->num;
	third = ((t_data*)(*a)->next->next->content)->num;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third && first > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}
