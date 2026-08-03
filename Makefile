NAME = minishell
CC = cc
C_FLAGS = -Wall -Wextra -Werror

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_BUILT_IN = env.c pwd.c cd.c export.c unset.c ft_exit.c echo.c

SRC_ENVIRONMENT = environment.c free_env.c get_value.c set_value.c \
				  get_envp.c is_valid_identifier.c

SRC_UTILS = free_cmd_star.c free_exp.c free_tokens.c full_cleanup.c \
			minishell_error.c

SRC_EXECUTION = free_stuff.c is_builtin.c execution.c \
			run_command.c run_pipeline.c get_path.c

SRC_PARSING = Expansion/count_for_expand.c Expansion/init_struct_exp.c \
			Expansion/expansion.c Expansion/modify_str.c\
			Lexer/create_tab.c Lexer/lexing.c \
			Parser/change_fd.c Parser/change_fd_heredoc.c \
			Parser/check_syntax.c Parser/parse.c Parser/parse_utils.c \
			Shell_struct/init_shell.c \
			Tokens/init_token.c

SRC_SIGNAL = signal.c

SRC = Main.c \
	  $(addprefix Built_in/, $(SRC_BUILT_IN)) \
	  $(addprefix Environment/, $(SRC_ENVIRONMENT)) \
	  $(addprefix Execution/, $(SRC_EXECUTION)) \
	  $(addprefix Utils/, $(SRC_UTILS)) \
	  $(addprefix Parsing/, $(SRC_PARSING)) \
	  $(addprefix Signal/, $(SRC_SIGNAL)) \
	  
OBJ = $(SRC:.c=.o)

DEPENDENCIES = $(OBJ:.o=.d)

INCLUDES = -I Includes -I $(LIBFT_DIR)

all: $(LIBFT) $(NAME)

-include $(DEPENDENCIES)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(C_FLAGS) $(OBJ) $(LIBFT) -o $(NAME) -lreadline

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

