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

void	ten_sort(t_list **a, t_list **b, size_t size)
{

}

/*
For 4 ≤ n ≤ 10

Push the smallest elements to B until A has only 3 elements

Repeat while size(A) > 3:

Find the position of the minimum in A

Bring it to the top with the cheaper of:

ra repeated pos times

rra repeated size-pos times

pb

Sort the 3 remaining in A using sort_3

Insert everything back from B into A efficiently
Repeat while B not empty:

Let x be the top of B

Find where x should be inserted in A:

the position of the first element in A that is > x

(if none, insert after the max / before the min)

Rotate A (ra/rra) the shortest way to bring that insert position to the top

pa

Final rotate A so the minimum is on top (cheapest ra vs rra)
*/