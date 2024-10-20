# Push_Swap MAKEFILE

PUSH_SWAP	= push_swap.a
HEADER 	= push_swap.h
BONUS	= checker

SRC = push_swap.c \
      operations.c \
      sort_large.c \
      sort_small.c \
      utils.c 

OBJ = $(SRC:.c=.o)

CC		= gcc 
CFLAGS	= -Wall -Werror -Wextra -I$(HEADER)

LIBFTNAME = libft.a
LIBFTPATH= ./libft
 
all: $(PUSH_SWAP)

$(PUSH_SWAP): $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)
# $(PUSH_SWAP): $(OBJ)
# 	@make -C $(LIBFTPATH)
# 	@cp $(LIBFTPATH)/$(LIBFTNAME) $(PUSH_SWAP)
# 	@ar -rcs $(PUSH_SWAP) $(OBJ) 
# 	@echo "$(PUSH_SWAP) created"

%.o: %.c
	@$(COMPILE) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIBFTPATH)
	@echo "Object files deleted"

fclean: clean
	@rm -f $(PUSH_SWAP) $(LIBFTNAME)
	@make fclean -C $(LIBFTPATH)
	@echo "$(PUSH_SWAP) deleted"

re: fclean all

.PHONY: all clean fclean re