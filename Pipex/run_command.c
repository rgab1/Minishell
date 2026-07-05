/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:48:57 by grivault          #+#    #+#             */
/*   Updated: 2026/07/06 00:17:06 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	close_fds(t_cmd	*current)
{
	if (current->in_fd > 2)
	{
		close(current->in_fd);
		current->in_fd = -1;
	}
	if (current->out_fd > 2)
	{
		close(current->out_fd);
		current->out_fd = -1;
	}
}

void	run_command(t_cmd *current, char **envp, t_shell *shell)
{
	char	*path;
	int		exit_code;

	if (current->in_fd == -1 || current->out_fd == -1)
		return (full_cleanup(shell), exit(1));
	path = get_path(shell, current->cmd[0]);
	if (!path)
	{
		if (ft_strchr(current->cmd[0], '/'))
			minishell_error(current->cmd[0], ERROR_NO_FILE);
		else
			minishell_error(current->cmd[0], ERROR_CMD_NOT_FOUND);
		return (full_cleanup(shell), exit(127));
	}
	dup2(current->in_fd, 0);
	dup2(current->out_fd, 1);
	close_fds(current);
	execve(path, current->cmd, envp);
	minishell_error(current->cmd[0], strerror(errno));
	exit_code = 127;
	if (access(path, X_OK) != 0)
		exit_code = 126;
	return (free(path), free_envp(envp), full_cleanup(shell), exit(exit_code));
}
