#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct s_env
{
	char *key;
	char *value;
	struct s_env *next;
}				t_env;

# include <stdio.h>
# include <libft.h>
# include <stdlib.h>
# include <unistd.h>

void	env(void);
void	pwd(void);
void	cd(char *path);

#endif 
