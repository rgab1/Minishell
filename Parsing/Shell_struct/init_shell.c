/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 16:22:47 by hassmou           #+#    #+#             */
/*   Updated: 2026/07/15 17:37:29 by hassmou          ###   ########.fr       */
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
	return (shell);
}

t_shell	*manage_shell(char **envp, char *line)
{
	char		**lex;
	t_tokens	*nodes;
	t_shell		*shell;
	t_cmd		*cmd;

	shell = shell_init();
    shell->line = line;
	shell->env = env_init(envp);
	lex = split_star(line, shell->env);
	if (!lex)
		return (exit_free(nodes, shell->cmd, "Error : Invalide Syntaxe"), NULL);
	nodes = manage_token(lex);
	print_lst(nodes);
	shell->cmd = create_cmd_struct(nodes);
	if (!cmd)
		return (exit_free(nodes, shell->cmd, "Error : IDK"), NULL);
}
