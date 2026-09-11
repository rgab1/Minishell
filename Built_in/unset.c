/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 21:04:10 by grivault          #+#    #+#             */
/*   Updated: 2026/09/11 18:32:50 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	unset(t_shell *shell)
{
	size_t	i;
	int		exit_status;

	i = 1;
	exit_status = 0;
	if (!shell->cmd->cmd[1])
		return (exit_status);
	while (shell->cmd->cmd[i])
	{
		if (!is_valid_identifier(shell->cmd->cmd[i]))
		{
			minishell_error("unset", ERROR_IDENTIFIER, shell->cmd->cmd[i]);
			exit_status = 1;
		}
		else
			del_env_node(&shell->env, shell->cmd->cmd[i]);
		i++;
	}
	return (exit_status);
}
