/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 19:25:35 by grivault          #+#    #+#             */
/*   Updated: 2026/08/22 18:08:30 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	dup_fds(t_cmd *current)
{
	if (current->in_fd > 2 || current->in_fd == 0)
		dup2(current->in_fd, 0);
	if (current->out_fd > 2 || current->out_fd == 1)
		dup2(current->out_fd, 1);
}

static void	exec_builtin_utils(t_shell *shell)
{
	if (shell->cmd->in_fd != -2 && shell->cmd->in_fd > 2)
		dup2(shell->cmd->in_fd, 0);
	if (shell->cmd->out_fd != -2 && shell->cmd->out_fd > 2)
		dup2(shell->cmd->out_fd, 1);
}

static void	exec_builtin(t_shell *shell, int *pid, size_t func_index)
{
	int			exit_code;
	static int	(*builtins[7])(t_shell *shell) = {cd, echo, env, export, pwd,
		unset, ft_exit};

	if (*pid == 0)
	{
		dup_fds(shell->cmd);
		exit_code = builtins[func_index](shell);
		return (full_cleanup(shell), exit(exit_code));
	}
	else
	{
		shell->save_in = dup(0);
		shell->save_out = dup(1);
		exec_builtin_utils(shell);
		shell->exit_code = builtins[func_index](shell);
		dup2(shell->save_in, 0);
		dup2(shell->save_out, 1);
		close(shell->save_in);
		close(shell->save_out);
	}
}

int	is_builtin(t_shell *shell, int *pid)
{
	size_t		i;
	static char	*builtins[8] = {"cd", "echo", "env", "export", "pwd", "unset",
		"exit", NULL};

	if (!shell)
		exit_error(ERROR_SHELL_NDEF_5, 5);
	if (!shell->cmd)
		exit_error(ERROR_CMD_NDEF_6, 6);
	if (!shell->cmd->cmd)
		exit_error(ERROR_CMD_EMPTY_7, 7);
	i = 0;
	while (builtins[i])
	{
		if (ft_strncmp(shell->cmd->cmd[0], builtins[i], 10) == 0)
			return (exec_builtin(shell, pid, i), 1);
		i++;
	}
	return (0);
}
