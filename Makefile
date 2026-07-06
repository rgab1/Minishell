NAME = minishell
CC = cc
C_FLAGS = -Wall -Wextra -Werror

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_BUILT_IN = env.c pwd.c cd.c export.c unset.c ft_exit.c echo.c

SRC_ENVIRONMENT = environment.c free_env.c get_value.c set_value.c \
				  get_envp.c is_valid_identifier.c

SRC_UTILS = full_cleanup.c minishell_error.c

SRC_EXECUTION = free_stuff.c is_builtin.c execution.c \
			run_command.c run_pipeline.c get_path.c

SRC = test_execution.c \
	  $(addprefix Built_in/, $(SRC_BUILT_IN)) \
	  $(addprefix Environment/, $(SRC_ENVIRONMENT)) \
	  $(addprefix Execution/, $(SRC_EXECUTION)) \
	  $(addprefix Utils/, $(SRC_UTILS)) \
	  
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

.PHONY: all clean fclean re redo

