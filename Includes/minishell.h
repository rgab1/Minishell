#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <libft.h>
# include <stdlib.h>
# include <unistd.h>


# include <pipex.h>
# include <environment.h>
# include <built_in.h>

typedef struct	s_shell
{
	t_env	*env;
	t_cmd	*cmd;
	int		exit_code;
}				t_shell;

void	free_shell(t_shell *shell);

#endif 
