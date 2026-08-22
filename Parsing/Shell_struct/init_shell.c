/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhalmi <hrhalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 16:22:47 by hassmou           #+#    #+#             */
/*   Updated: 2026/08/21 02:32:38 by hrhalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	*shell_init(char **envp)
{
	t_shell	*shell;

	shell = malloc(sizeof(t_shell));
	if (!shell)
		return (minishell_error("Malloc", ERROR_MALLOC_FAILED_4), NULL);
	shell->env = env_init(envp);
	shell->cmd = NULL;
	shell->line = NULL;
	shell->exit_code = 0;
	return (shell);
}

t_shell	*manage_shell(char *line, t_shell *shell)
{
	char		**lex;
	t_tokens	*tokens;

	tokens = NULL;
	shell->line = line;
	lex = split_star(line);
	if (!lex)
		return (shell);
	tokens = manage_token(lex, shell);
	free(lex);
	if (check_syntax(tokens))
	{
		free_tokens(tokens);
		shell->exit_code = 2;
		return (shell);
	}
	// print_lst(tokens);
	shell->cmd = create_cmd_struct(tokens);
	free_tokens(tokens);
	if (!shell->cmd)
	{
		shell->exit_code = 1;
		return (shell);
	}
	return (shell);
}
