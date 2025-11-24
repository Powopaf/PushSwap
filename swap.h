/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <pifourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 10:35:03 by pifourni          #+#    #+#             */
/*   Updated: 2025/11/24 10:35:04 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
# define SWAP_H

# include "list.h"

void	sa(struct node	*stack_a);
void	sb(struct node	*stack_b);
void	ss(struct node	*stack_a, struct node	*stack_b);
void	pa(struct node	*stack_a, struct node	*stack_b);
void	pb(struct node	*stack_a, struct node	*stack_b);
void	ra(struct node	*stack_a);
void	rb(struct node	*stack_b);
void	rr(struct node	*stack_a, struct node	*stack_b);
void	rra(struct node	*stack_a);
void	rrb(struct node	*stack_b);
void	rrr(struct node	*stack_a, struct node	*stack_b);
#endif
