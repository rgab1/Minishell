/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipeline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:49:06 by grivault          #+#    #+#             */
/*   Updated: 2026/03/18 17:49:08 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <pipex.h>

void	run_pipeline(t_cmd *current, char **envp, int *pid)
{
	int		fd[2];
	t_cmd	*head;

	head = current;
	while (current)
	{
		if (current->next)
		{
			pipe(fd);
			current->out_fd = fd[1];
			current->next->in_fd = fd[0];
		}
		*pid = fork();
		if (*pid == 0)
		{
			if (current->next)
				close(fd[0]);
			run_command(current, envp, head);
		}
		close(current->in_fd);
		close(current->out_fd);
		current = current->next;
	}
}
