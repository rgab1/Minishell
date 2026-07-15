/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 16:22:47 by hassmou           #+#    #+#             */
/*   Updated: 2026/07/15 16:53:01 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell *shell_init()
{
    t_shell *shell;

    shell = malloc(sizeof(t_shell));
    if (!shell)
        return (/*exit_error("malloc failed")*/NULL); // WIP 
    shell->env = NULL;
    shell->cmd = NULL;
    shell->line = NULL;
    return (shell);
}

t_shell *manage_shell(char **envp, char *line)
{
    char        **lex;
    t_tokens	*nodes;
    t_shell     *shell;
    t_cmd		*cmd;

    shell = shell_init();
    shell->env = env_init(envp);
    lex = split_star(line, env);
	if (!lex)
		return (exit_free(nodes, cmd, "Error : Invalide Syntaxe"), NULL);
    nodes = manage_token(lex);
    print_lst(nodes);
	shell->cmd = create_cmd_struct(nodes);
	if (!cmd)
		return (exit_free(nodes, cmd, "Error : IDK"), 1);
}
