/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:48:57 by grivault          #+#    #+#             */
/*   Updated: 2026/04/10 21:19:28 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <pipex.h>
#include <libft.h>

static void close_last(t_cmd *current)
{
	while (current->next)
		current = current->next;
	close(current->out_fd);
}

void run_command(t_cmd *current, char **envp, t_cmd *head)
{
	char *path;
	int exit_code;

	if (current->in_fd == -1 || current->out_fd == -1)
		return (free_list(head), exit(1));
	path = get_path(current->cmd[0], envp);
	if (!path)
	{
		ft_putstr_fd(current->cmd[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		close(current->in_fd);
		close(current->out_fd);
		return (close_last(current), free_list(head), exit(127));
	}
	dup2(current->in_fd, 0);
	dup2(current->out_fd, 1);
	close(current->in_fd);
	close(current->out_fd);
	close_last(current);
	execve(path, current->cmd, envp);
	perror(current->cmd[0]);
	exit_code = 127;
	if (access(path, X_OK) != 0)
		exit_code = 126;
	return (free(path), free_list(head), exit(exit_code));
}
