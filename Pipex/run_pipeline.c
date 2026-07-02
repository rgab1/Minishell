/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipeline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:49:06 by grivault          #+#    #+#             */
/*   Updated: 2026/07/02 19:36:59 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <pipex.h>

void	run_pipeline(t_shell *shell, int *pid)
{
	int		fd[2];

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
			is_builtin(shell, pid);
			run_command(shell->cmd, get_envp(shell), shell);
		}
		if (shell->cmd->in_fd > 2)
			close(shell->cmd->in_fd);
		if (shell->cmd->out_fd > 2)
			close(shell->cmd->out_fd);
		shell->cmd = shell->cmd->next;
	}
}
