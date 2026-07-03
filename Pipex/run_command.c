/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:48:57 by grivault          #+#    #+#             */
/*   Updated: 2026/07/03 18:32:31 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <pipex.h>
#include <libft.h>

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
		ft_putstr_fd(current->cmd[0], 2);
		if (ft_strchr(current->cmd[0], '/'))
			ft_putstr_fd(": No such file or directory\n", 2);
		else
			ft_putstr_fd(": command not found\n", 2);
		return (full_cleanup(shell), exit(127));
	}
	dup2(current->in_fd, 0);
	dup2(current->out_fd, 1);
	close_fds(current);
	execve(path, current->cmd, envp);
	perror(current->cmd[0]);
	exit_code = 127;
	if (access(path, X_OK) != 0)
		exit_code = 126;
	return (free(path), free_envp(envp), full_cleanup(shell), exit(exit_code));
}
