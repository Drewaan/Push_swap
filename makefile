# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 19:52:16 by aamaya-g          #+#    #+#              #
#    Updated: 2024/11/08 07:00:19 by aamaya-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CCFLAGS = -Wall -Wextra -Werror -g

#colors
COLOR_GREEN = \033[0;32m
COLOR_RESET = \033[0m

#sources
SRC_DIR = sources/
SRC_FILES = algorithm.c ft_split.c input_checker.c list_utils.c range.c sort_array.c stack_basic.c stack_order_1.c stack_order_2.c utils.c main.c
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(SRC:.c=.o)

#program
all: $(NAME)
	@echo "$(COLOR_GREEN)------------ PROCESS FINISHED ------------ $(COLOR_RESET)"

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@
	@echo "$(COLOR_GREEN)------------ MESSAGE: $@ COMPILED ------------ $(COLOR_RESET)"
	

#additional

clean:
	rm -f $(OBJ)
	@echo "$(COLOR_GREEN)------------ MESSAGE: CLEANING COMPLETED ------------ $(COLOR_RESET)"
	
fclean: 
	rm -f $(NAME)
	rm -f $(OBJ)
	@echo "$(COLOR_GREEN)------------ MESSAGE: CLEANING COMPLETED ------------ $(COLOR_RESET)"

re: fclean all


.PHONY:	all clean fclean re