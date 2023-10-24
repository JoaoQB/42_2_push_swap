# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 16:17:47 by jqueijo-          #+#    #+#              #
#    Updated: 2023/10/24 16:18:37 by jqueijo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

SRC = push_swap.c \
	stack_creation.c \
	input_aux.c \
	debugging.c \

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar -rcs $@ $(OBJ)
	cc -g -o push_swap push_swap.a -fsanitize=address

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, bonus, clean, fclean, re
