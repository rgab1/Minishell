NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_BUILT_IN = env.c pwd.c

SRC = minishell.c \
	  $(addprefix Built_in/, $(SRC_BUILT_IN))

OBJ = $(SRC:.c=.o)

INCLUDES = -I . -I $(LIBFT_DIR)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(C_FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

redo: re
	make clean
	clear

.PHONY: all clean fclean re 

