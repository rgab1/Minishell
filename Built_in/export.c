/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 21:09:27 by grivault          #+#    #+#             */
/*   Updated: 2026/05/07 18:11:55 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <environment.h>

//a coder: print_env_alphabetical

void	export(t_shell *shell)
{
	if (!shell->cmd)
		exit_error("Error a definir", 3);
	if (shell->cmd->cmd[1])
		new_env_node(&shell->env, extract_key_value(shell->cmd->cmd[1]));
//	else
//		print_env_alphabetical(shell->env);
	exit(0);
}
