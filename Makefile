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
CFLAGS = -Wall -Wextra -Werror
LIB = libft/libft.a
SRC = ./swap.c \
	  ./src/list/node.c \
	  ./src/list/list.c \
	  ./src/radix/sort.c \
	  ./src/operations/push.c \
	  ./src/operations/exchange.c \
	  ./src/operations/rotate.c \
	  ./src/operations/reverse.c

OBJ = $(SRC:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) -o $(NAME) $^ $(LIB)

$(LIB):
	${MAKE} -C libft

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)
	${MAKE} -C libft clean

fclean: clean
	rm -f $(NAME)
	${MAKE} -C libft fclean

re: fclean all
