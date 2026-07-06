/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 22:18:06 by grivault          #+#    #+#             */
/*   Updated: 2026/07/06 06:13:25 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>

# include <errors.h>
# include <libft.h>
# include <execution.h>
# include <environment.h>
# include <built_in.h>

typedef struct s_shell
{
	t_env	*env;
	t_cmd	*cmd;
	int		exit_code;
}				t_shell;

void	full_cleanup(t_shell *shell);
void	minishell_error(char *context, char *error_msg);

#endif 
