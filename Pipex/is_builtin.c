/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 19:25:35 by grivault          #+#    #+#             */
/*   Updated: 2026/07/02 19:37:21 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	exec_builtin(t_shell *shell, int *pid, size_t func_index)
{
	int			save_in;
	int			save_out;
	static int	(*builtins[6])(t_shell *shell) = {
		cd, echo, env, export, pwd, unset
	};

	if (*pid == 0)
		return (close_and_free_all(shell), exit(builtins[func_index](shell)));
	else
	{
		save_in = dup(0);
		save_out = dup(1);
		dup2(shell->cmd->in_fd, 0);
		dup2(shell->cmd->out_fd, 1);
		shell->exit_code = builtins[func_index](shell);
		dup2(save_in, 0);
		dup2(save_out, 1);
		close(save_in);
		close(save_out);
	}
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
