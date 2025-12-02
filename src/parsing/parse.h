/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <pifourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:21:16 by pifourni          #+#    #+#             */
/*   Updated: 2025/11/26 15:21:21 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "../../libft/libft.h"

typedef struct s_data
{
	int	num;
	int	index;
}	t_data;	

t_list	*parser(int argc, char **argv, size_t *i);
void	free_split(char **split);
void	delete_data(void *data);
#endif