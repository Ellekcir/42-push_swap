NAME    = push_swap
HEADER  = push_swap.h

SRC     = op_rotate.c \
		op_rev_rotate.c \
		op_push.c \
		op_swap.c \
		sort_three.c \
		sort_insertion.c \
		parse.c \
		validation.c \
		stack.c \
		utils.c \
		push_swap.c \
		main.c

#		sort_radix.c 
#		sort_chunk.c 
OBJ     = $(SRC:.c=.o)

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

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBFTPATH) -lft
	@echo "$(CYAN)$(NAME) created$(DEFAULT)"

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

norm:
	@$(NORMINETTE) $(SRC) $(HEADER) $(NORM_FLAGS)
	@echo "$(GREEN)Norminette checks completed!$(RESET)"

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIBFTPATH)
	@echo "$(RED)Object files deleted$(DEFAULT)"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFTPATH)
	@echo "$(RED)$(NAME) deleted$(DEFAULT)"

re: fclean all

.PHONY: all clean fclean re
