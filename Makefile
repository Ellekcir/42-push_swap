NAME    = push_swap
HEADER  = push_swap.h

SRC     = op_rotate.c \
		op_rev_rotate.c \
		op_push.c \
		op_swap.c \
		sort_small.c \
		sort_medium.c \
		sort_large1.c \
		sort_large2.c \
		parse.c \
		validation.c \
		stack.c \
		utils_helpers.c \
		utils_prints.c \
		push_swap.c \
		main.c

# Object files will be placed in the obj directory
OBJ_DIR = obj
OBJ     = $(SRC:.c=.o)
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(notdir $(OBJ)))

# COMPILER + FLAGS
CC      = gcc
CFLAGS  = -Wall -Werror -Wextra -I. 

# Norminette-related variables
NORMINETTE = norminette
NORM_FLAGS = -R CheckForbiddenSourceHeader

# LIBFT SETUP
LIBFTNAME   = libft.a
LIBFTPATH   = ./libft
LIBFT       = $(LIBFTPATH)/$(LIBFTNAME)

# Color codes
DEFAULT = \033[0m
CYAN = \033[36m
RED = \033[31m
GREEN = \033[0;32m

# BUILD TARGETS
all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFTPATH)

$(NAME): $(OBJ_FILES)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) -L$(LIBFTPATH) -lft
	@echo "$(CYAN)$(NAME) created$(DEFAULT)"

# Rule to compile .c files into .o files inside the obj directory
$(OBJ_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

norm:
	@$(NORMINETTE) $(SRC) $(HEADER) $(NORM_FLAGS)
	@echo "$(GREEN)Norminette checks completed!$(DEFAULT)"

clean:
	@rm -f $(OBJ_FILES)
	@make clean -C $(LIBFTPATH)
	@echo "$(RED)Object files deleted$(DEFAULT)"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFTPATH)
	@echo "$(RED)$(NAME) deleted$(DEFAULT)"

re: fclean all

.PHONY: all clean fclean re norm
