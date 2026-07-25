/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 16:22:47 by hassmou           #+#    #+#             */
/*   Updated: 2026/07/25 16:34:03 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	*shell_init(char **envp)
{
	t_shell	*shell;

	shell = malloc(sizeof(t_shell));
	if (!shell)
		return (NULL); // WIP
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
	if (!check_syntax)
	{
		free_tokens(tokens);
		shell->exit_code = 2;
		return (shell);
	}
	print_lst(tokens);
	printf("expand end\n");
	shell->cmd = create_cmd_struct(tokens);
	if (!shell->cmd)
	{
		shell->exit_code = 1;
		return (shell);
	}
	put_cmd(shell->cmd);
	return (shell);
}

// 3. VÉRIFICATION DES ERREURS D'OUVERTURE DE FICHIER (open)
	// if (!shell->cmd)
	// {
	// 	// Si create_cmd_struct a échoué (ex: perror a affiché "No such file..."), 
	// 	// on ne quitte pas ! On met juste à jour le code d'erreur.
	// 	shell->exit_code = 1; 
	// 	return (shell); // Le shell survit !
	// }