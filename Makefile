# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 16:17:47 by jqueijo-          #+#    #+#              #
#    Updated: 2023/12/12 18:12:11 by jqueijo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c \
	stack_creation.c \
	stack_input_aux.c \
	ft_error.c \
	str_aux.c \
	ft_split.c \
	swap.c \
	push.c \
	rotate.c \
	reverse_rotate.c \
	small_sort.c \
	stack_handling_aux.c \
	big_sort.c \
	stack_handling.c \
	stack_sorting.c \

CC = cc
CFLAGS = -O3 -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	cc -o push_swap $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, bonus, clean, fclean, re
