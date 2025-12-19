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
	if (!a || !*a || !(*a)->next)
		return ;
	if (((t_data *)(*a)->content)->num > ((t_data *)(*a)->next->content)->num)
		sa(a);
}

void	three_sort(t_list **a)
{
	int	first;
	int	second;
	int	third;

	first = ((t_data *)(*a)->content)->num;
	second = ((t_data *)(*a)->next->content)->num;
	third = ((t_data *)(*a)->next->next->content)->num;
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

static int	find_min(t_list *a)
{
	int		min;
	int		pos;
	int		best;
	t_list	*cur;

	min = ((t_data *)a->content)->num;
	best = 0;
	pos = 0;
	cur = a;
	while (cur)
	{
		if (((t_data *)cur->content)->num < min)
		{
			min = ((t_data *)cur->content)->num;
			best = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (best);
}

static void	rotate_min_push(t_list **a, t_list **b)
{
	int	pos;
	int	size;

	pos = find_min(*a);
	size = ft_lstsize(*a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(a);
	}
	pb(a, b);
}

void	small_sort(t_list **a, t_list **b)
{
	int	size;

	if (!a || !*a)
		return ;
	size = ft_lstsize(*a);
	if (size == 4)
	{
		rotate_min_push(a, b);
		three_sort(a);
		pa(a, b);
	}
	else if (size == 5)
	{
		rotate_min_push(a, b);
		rotate_min_push(a, b);
		three_sort(a);
		pa(a, b);
		pa(a, b);
	}
}
