#include "radix.h"

static int	find_min_pos(t_list *stack)
{
	int	pos;
	int	min;
	int	min_pos;

	pos = 0;
	min_pos = 0;
	min = ((t_data*)stack->content)->num;
	while (stack)
	{
		if (((t_data*)stack->content)->num < min)
		{
			min = ((t_data*)stack->content)->num;
			min_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (min_pos);
}

static int	find_insert_pos(t_list *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (((t_data*)stack->content)->num > value)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

static void	rotate_to_top(t_list **a, int pos, size_t size)
{
	int	i;

	if (pos <= (int)size / 2)
	{
		for (i = 0; i < pos; i++)
			ra(a);
	}
	else
	{
		for (i = 0; i < (int)size - pos; i++)
			rra(a);
	}
}

static void	put_back(t_list **a, t_list **b, int x, t_list *tmp, int insert_pos)
{
	x = ((t_data*)(*b)->content)->num;
	insert_pos = find_insert_pos(*a, x);
	if (insert_pos == -1)
	{
		int	max_pos = 0;
		int	max_val = ((t_data*)(*a)->content)->num;
		tmp = *a;
		int	pos = 0;
		while (tmp)
		{
			if (((t_data*)tmp->content)->num > max_val)
			{
				max_val = ((t_data*)tmp->content)->num;
				max_pos = pos;
			}
			tmp = tmp->next;
			pos++;
		}
		rotate_to_top(a, (max_pos + 1) % ft_lstsize(*a), ft_lstsize(*a));
	}
	else
		rotate_to_top(a, insert_pos, ft_lstsize(*a));
	pa(a, b);
}

void	ten_sort(t_list **a, t_list **b)
{
	while (ft_lstsize(*a) > 3)
	{
		rotate_to_top(a, find_min_pos(*a), ft_lstsize(*a));
		pb(a, b);
	}
	three_sort(a);
	while (*b)
	{
		put_back(a, b, 0, NULL, -1);
	}
	rotate_to_top(a, find_min_pos(*a), ft_lstsize(*a));
}
