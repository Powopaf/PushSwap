# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pifourni <pifourni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/24 10:34:38 by pifourni          #+#    #+#              #
#    Updated: 2025/11/24 10:34:41 by pifourni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


.PHONY: all clean fclean re

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB =
SRC = 

OBJ = $(SRC:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $+ $(LIB)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
