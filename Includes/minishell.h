/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 22:18:06 by grivault          #+#    #+#             */
/*   Updated: 2026/07/23 08:27:43 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <errno.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_shell
{
	t_env	*env;
	t_cmd	*cmd;
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


void		full_cleanup(t_shell *shell);
void		minishell_error(char *context, char *error_msg);

// init_shell.c
t_shell		*shell_init(void);
t_shell		*manage_shell(char **envp, char *line, t_shell *shell);

#endif
