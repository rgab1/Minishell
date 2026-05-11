/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 21:04:10 by grivault          #+#    #+#             */
/*   Updated: 2026/05/11 02:24:11 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	unset(t_shell *shell)
{
	size_t	i;

	i = 1;
	if (!shell->cmd->cmd[1])
		return (0);
	while (shell->cmd->cmd[i])
		del_env_node(&shell->env, shell->cmd->cmd[i++]);
	return (0);
}
