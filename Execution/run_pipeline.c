/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipeline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhalmi <hrhalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:49:06 by grivault          #+#    #+#             */
/*   Updated: 2026/09/11 18:55:52 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	pipe_assignement(int *fd, t_cmd *current)
{
	pipe(fd);
	if (current->out_fd == -2)
		current->out_fd = fd[1];
	else
	{
		close(fd[1]);
		fd[1] = -2;
	}
	if (current->next->in_fd == -2)
		current->next->in_fd = fd[0];
	else
	{
		close(fd[0]);
		fd[0] = -2;
	}
}

static void	close_fds(t_shell *shell)
{
	if (shell->cmd->in_fd > 2)
	{
		close(shell->cmd->in_fd);
		shell->cmd->in_fd = -2;
	}
	if (shell->cmd->out_fd > 2)
	{
		close(shell->cmd->out_fd);
		shell->cmd->out_fd = -2;
	}
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
			signal(SIGPIPE, SIG_IGN);
			is_builtin(shell, pid);
			run_command(shell->cmd, get_envp(shell), shell);
		}
		close_fds(shell);
		temp = shell->cmd->next;
		free_cmd(shell->cmd);
		shell->cmd = temp;
	}
}
