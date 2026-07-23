/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 16:22:47 by hassmou           #+#    #+#             */
/*   Updated: 2026/07/23 07:36:02 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	*shell_init(void)
{
	t_shell	*shell;

	shell = malloc(sizeof(t_shell));
	if (!shell)
		return (/*exit_error("malloc failed")*/ NULL); // WIP
	shell->env = NULL;
	shell->cmd = NULL;
	shell->line = NULL;
	shell->exit_code = 0;
	return (shell);
}

t_shell	*manage_shell(char **envp, char *line, t_shell *shell)
{
	char		**lex;
	t_tokens	*tokens;
	t_cmd		*cmd;

	tokens = NULL;
	cmd = NULL;
    shell->line = line;
	shell->env = env_init(envp);
	lex = split_star(line);
	if (!lex)
		return (exit_free(tokens, shell->cmd, "Error : Invalide Syntaxe split star"), NULL); // Utilisation de minishell_error()
	tokens = manage_token(lex, shell);
	print_lst(tokens);
	manage_expand(tokens, shell);
	shell->cmd = create_cmd_struct(tokens);
	if (!cmd)
		return (exit_free(tokens, shell->cmd, "Error : IDK"), NULL);
	return (shell);
}
