/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <pifourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:00:46 by pifourni          #+#    #+#             */
/*   Updated: 2025/11/24 11:00:48 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIST_H
# define LIST_H

struct node
{
	char		data;
	struct node	*next;
	struct node	*prev;
};

struct node	*new_node(char data);
void		push(struct node *n, struct node *stack);
struct node *pop(struct node *stack);

#endif