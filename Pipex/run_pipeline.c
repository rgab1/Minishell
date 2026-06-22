/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipeline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:49:06 by grivault          #+#    #+#             */
/*   Updated: 2026/06/22 23:17:40 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <pipex.h>

void	run_pipeline(t_shell *shell, int *pid)
{
	int		fd[2];
	t_cmd	*head;

	head = shell->cmd;
	while (shell->cmd)
	{
		if (shell->cmd->next)
		{
			pipe(fd);
			shell->cmd->out_fd = fd[1];
			shell->cmd->next->in_fd = fd[0];
		}
		*pid = fork();
		if (*pid == 0)
		{
			if (shell->cmd->next)
				close(fd[0]);
			if (is_builtin(shell, &pid)
				continue ;
			run_command(shell->cmd, get_envp(shell), head);
		}
		close(shell->cmd->in_fd);
		close(shell->cmd->out_fd);
		shell->cmd = shell->cmd->next;
	}
}
