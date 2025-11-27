/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <pifourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:25:37 by pifourni          #+#    #+#             */
/*   Updated: 2025/11/26 15:25:38 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "../../libft/libft.h"
# include "../parsing/parse.h"

int	error_message(char *msg);
t_list	*error_parsing(char **split, t_list *stack);

#endif