/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <pifourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:32:37 by pifourni          #+#    #+#             */
/*   Updated: 2025/11/26 16:32:39 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADIX_H
# define RADIX_H

# include "../../libft/libft.h"
# include "../parsing/parse.h"

void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	sort(t_list **stack_a, t_list **stack_b, size_t size);
void	sa(t_list **stack_a);
void	rra(t_list **stack_a);
void	two_sort(t_list **a);
void	three_sort(t_list **a);
void	ten_sort(t_list **a, t_list **b);

#endif
