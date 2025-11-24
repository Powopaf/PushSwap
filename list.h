/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <pifourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:00:46 by pifourni          #+#    #+#             */
/*   Updated: 2025/11/24 17:28:49 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

struct s_node
{
	char		data;
	struct s_node	*next;
	struct s_node	*prev;
};

struct s_node	*new_node(char data);
void		push(struct s_node *n, struct s_node *stack);
struct s_node	*pop(struct s_node *stack);
int				is_empty(struct s_node *stack);

#endif
