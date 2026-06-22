/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 22:59:26 by grivault          #+#    #+#             */
/*   Updated: 2026/06/22 23:07:42 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	close_and_free_all(shell)
{
	t_shell	*current;

	if (!shell || !shell->cmd)
		exit_error("shell or cmd struct are not defined", 4);
	if (shell->env)
		free_env(shell->env);
	current = shell->cmd;
	while (current)
	{
		close(current->in_fd);
		close(current->out_fd);
		free_cmd(current);
		current = current->next;
	}
}
