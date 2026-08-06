/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipeline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:49:06 by grivault          #+#    #+#             */
/*   Updated: 2026/08/06 16:27:54 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	pipe_assignement(int *fd, t_cmd *current)
{
	pipe(fd);
	current->out_fd = fd[1];
	current->next->in_fd = fd[0];
}

void	run_pipeline(t_shell *shell, int *pid)
{
	int		fd[2];
	t_cmd	*temp;

	while (shell->cmd)
	{
		if (shell->cmd->next)
			pipe_assignement(fd, shell->cmd);
		*pid = fork();
		if (*pid == 0)
		{
			signal(SIGINT, SIG_DFL);
			signal(SIGQUIT, SIG_DFL);
			if (shell->cmd->next)
				close(fd[0]);
			is_builtin(shell, pid);
			run_command(shell->cmd, get_envp(shell), shell);
		}
		if (shell->cmd->in_fd > 2)
			close(shell->cmd->in_fd);
		if (shell->cmd->out_fd > 2)
			close(shell->cmd->out_fd);
		temp = shell->cmd->next;
		free_cmd(shell->cmd);
		shell->cmd = temp;
	}
}
