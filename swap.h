/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <pifourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 10:35:03 by pifourni          #+#    #+#             */
/*   Updated: 2025/11/24 17:09:03 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
# define SWAP_H

# include "src/list/list.h"
#include <stddef.h>

void	sa(struct s_node *stack_a);
void	sb(struct s_node *stack_b);
void	ss(struct s_node *stack_a, struct s_node *stack_b);
void	pa(struct s_node *stack_a, struct s_node *stack_b);
void	pb(struct s_node *stack_a, struct s_node *stack_b);
void	ra(struct s_node *stack_a);
void	rb(struct s_node *stack_b);
void	rr(struct s_node *stack_a, struct s_node *stack_b);
void	rra(struct s_node *stack_a);
void	rrb(struct s_node *stack_b);
void	rrr(struct s_node *stack_a, struct s_node *stack_b);
#endif
