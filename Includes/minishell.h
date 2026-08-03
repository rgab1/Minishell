/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 22:18:06 by grivault          #+#    #+#             */
/*   Updated: 2026/08/03 06:33:27 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <sys/wait.h>
# include <signal.h>

struct s_env;
struct s_cmd;

typedef struct s_shell
{
	struct s_env	*env;
	struct s_cmd	*cmd;
	char	*line;
	int		exit_code;
}			t_shell;

# include "environment.h"
# include "execution.h"
# include "parsing.h"
# include "built_in.h"
# include "errors.h"
# include "expansion.h"
# include "libft.h"

extern int g_signal_status;

void		start_minishell(int ac, char **av);
void		end_of_minishell(t_shell *shell, char *line);

void		full_cleanup(t_shell *shell);
void		minishell_error(char *context, char *error_msg);

// init_shell.c
t_shell		*shell_init(char **envp);
t_shell		*manage_shell(char *line, t_shell *shell);

// Signaux.c
void    	sigint_handler(int sig);
void    	check_g_status(t_shell *shell);

#endif
