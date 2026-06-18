/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 19:25:35 by grivault          #+#    #+#             */
/*   Updated: 2026/06/03 20:27:14 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	exec_builtin(t_shell *shell, int *pid, size_t func_index)
{
	int			exit_status;
	static int	(*builtins[6])(t_shell *shell) = {
		cd, echo, env, export, pwd, unset
	};

	exit_status = builtins[func_index](shell);
	*pid = fork();
	if (*pid == 0)
		exit(exit_status);
	close(shell->cmd->in_fd);
	close(shell->cmd->out_fd);
	shell->cmd = shell->cmd->next;
}

int	is_builtin(t_shell *shell, int *pid)
{
	size_t		i;
	static char	*builtins[7] = {
		"cd", "echo", "env", "export", "pwd", "unset", NULL
	};

	if (!shell ||!shell->cmd || !shell->cmd->cmd || !shell->cmd->cmd[0])
		exit_error("something in the shell is not defined", 4);
	i = 0;
	while (builtins[i])
	{
		if (ft_strncmp(shell->cmd->cmd[0], builtins[i], 10) == 0)
			return (exec_builtin(shell, pid, i), 1);
		i++;
	}
	return (0);
}
