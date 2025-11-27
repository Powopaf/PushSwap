# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pifourni <pifourni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/24 10:34:38 by pifourni          #+#    #+#              #
#    Updated: 2025/11/24 12:02:24 by pifourni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


.PHONY: all clean fclean re

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
LIB = libft/libft.a -fsanitize=address
SRC = ./swap.c \
	  ./src/parsing/parse.c \
	  ./src/error/error.c \
	  ./src/radix/radix.c \
	  ./src/radix/operations.c

OBJ = $(SRC:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(CC) -o $(NAME) $^ $(LIB)

$(LIB):
	${MAKE} -C libft bonus

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)
	${MAKE} -C libft clean

fclean: clean
	rm -f $(NAME)
	${MAKE} -C libft fclean

re: fclean all
