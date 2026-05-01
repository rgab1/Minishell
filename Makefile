NAME = minishell
CC = cc
C_FLAGS = -Wall -Wextra -Werror

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_BUILT_IN = env.c pwd.c cd.c

SRC_ENVIRONMENT = environment.c free_stuff.c

SRC = minishell.c \
	  $(addprefix Built_in/, $(SRC_BUILT_IN)) \
	  $(addprefix Environment/, $(SRC_ENVIRONMENT))

OBJ = $(SRC:.c=.o)

DEPENDENCIES = $(OBJ:.o=.d)

INCLUDES = -I Includes -I $(LIBFT_DIR)

all: $(LIBFT) $(NAME)

-include $(DEPENDENCIES)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(C_FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(C_FLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(DEPENDENCIES)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

redo: re
	make clean
	clear

.PHONY: all clean fclean re 

