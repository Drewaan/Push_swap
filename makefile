NAME    = push_swap
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj

SRC     = \
	$(SRC_DIR)/algorithm_atob.c\
	$(SRC_DIR)/check_input.c\
	$(SRC_DIR)/fill_stack.c \
	$(SRC_DIR)/find_range.c \
	$(SRC_DIR)/ft_atol.c \
	$(SRC_DIR)/ft_calloc.c \
	$(SRC_DIR)/ft_split.c \
	$(SRC_DIR)/list_basic.c \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/sort_arr.c \
	$(SRC_DIR)/stack_operations_1.c\
	$(SRC_DIR)/stack_operations_2.c\
	$(SRC_DIR)/stack_sort.c\

OBJ     = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: re
	./$(NAME) $(ARGS)

.PHONY: all clean fclean re run⏎  