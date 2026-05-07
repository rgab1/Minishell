#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <libft.h>
# include <stdlib.h>
# include <unistd.h>
# include <environment.h>
# include <pipex.h>

typedef struct	s_shell
{
	t_env	*env;
	t_cmd	*cmd;

}				t_shell;

#endif 
