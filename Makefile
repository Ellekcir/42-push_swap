NAME    = push_swap
HEADER  = push_swap.h

SRC     = op_rotate.c \
		op_rev_rotate.c \
		op_push.c \
		op_swap.c \
		sort_radix.c \
		sort_five_or_less.c \
		input_validation.c \
		stack.c \
		utils.c \
		push_swap.c 


OBJ     = $(SRC:.c=.o)

# COMPILER + FLAGS
CC      = cc
CFLAGS  = -Wall -Werror -Wextra -I.

# LIBFT SETUP
LIBFTNAME   = libft.a
LIBFTPATH   = ./libft
LIBFT       = $(LIBFTPATH)/$(LIBFTNAME)

# BUILD TARGETS
all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFTPATH)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBFTPATH) -lft
	@echo "$(NAME) created"

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIBFTPATH)
	@echo "Object files deleted"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFTPATH)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all clean fclean re
