/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_cleanup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 22:59:26 by grivault          #+#    #+#             */
/*   Updated: 2026/07/06 05:44:13 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	full_cleanup(t_shell *shell)
{
	t_cmd	*current;
	t_cmd	*temp;

	if (!shell)
		exit_error(ERROR_SHELL_NDEF_5, 5);
	if (shell->env)
		free_env(shell->env);
	if (shell->cmd)
	{
		current = shell->cmd;
		while (current)
		{
			temp = current->next;
			free_cmd(current);
			current = temp;
		}
	}
	free(shell);
}
