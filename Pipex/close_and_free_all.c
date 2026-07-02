/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_and_free_all.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 22:59:26 by grivault          #+#    #+#             */
/*   Updated: 2026/07/02 19:40:40 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	close_and_free_all(t_shell *shell)
{
	t_cmd	*current;
	t_cmd	*temp;

	if (!shell || !shell->cmd)
		exit_error("shell or cmd struct are not defined", 4);
	if (shell->env)
		free_env(shell->env);
	current = shell->cmd;
	while (current)
	{
		temp = current->next;
		if (current->in_fd > 2)
			close(current->in_fd);
		if (current->out_fd > 2)
			close(current->out_fd);
		free_cmd(current);
		current = temp;
	}
}
