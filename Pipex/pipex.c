/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:46:53 by grivault          #+#    #+#             */
/*   Updated: 2026/03/18 17:47:14 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <pipex.h>
#include <libft.h>

int	main(int ac, char **av, char **envp)
{
	t_cmd	*head;
	int		status;
	int		exit_code;
	int		pid;

	exit_code = 0;
	pid = -1;
	status = 0;
	if (ac < 5)
	{
		ft_putstr_fd("Error: Bad arguments\n", 2);
		return (1);
	}
	head = parsing(av);
	run_pipeline(head, envp, &pid);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		exit_code = WEXITSTATUS(status);
	while (wait(NULL) > 0)
		continue ;
	return (free_list(head), exit_code);
}
