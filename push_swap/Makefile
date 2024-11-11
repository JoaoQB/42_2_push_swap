# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 16:17:47 by jqueijo-          #+#    #+#              #
#    Updated: 2024/11/11 11:50:48 by jqueijo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_PATH = ./srcs
ACTIONS = $(SRC_PATH)/actions
PARSING = $(SRC_PATH)/parsing
SORT = $(SRC_PATH)/sort
STRUCT = $(SRC_PATH)/struct

SRC = main.c \
	$(PARSING)/stack_input_aux.c \
	$(PARSING)/ft_error.c \
	$(PARSING)/str_aux.c \
	$(PARSING)/ft_split.c \
	$(STRUCT)/stack_creation.c \
	$(STRUCT)/stack_handling.c \
	$(STRUCT)/stack_handling_aux.c \
	$(ACTIONS)/swap.c \
	$(ACTIONS)/push.c \
	$(ACTIONS)/rotate.c \
	$(ACTIONS)/reverse_rotate.c \
	$(SORT)/small_sort.c \
	$(SORT)/big_sort.c \
	$(SORT)/stack_sorting.c \

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
