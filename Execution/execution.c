/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 13:49:40 by grivault          #+#    #+#             */
/*   Updated: 2026/07/06 06:11:15 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	single_cmd(t_shell *shell, int *pid)
{
	int	status;

	*pid = -1;
	if (is_builtin(shell, pid))
		return ;
	*pid = fork();
	if (*pid == 0)
		run_command(shell->cmd, get_envp(shell), shell);
	waitpid(*pid, &status, 0);
	if (WIFEXITED(status))
		shell->exit_code = WEXITSTATUS(status);
}

void	execution(t_shell *shell)
{
	int	pid;
	int	status;

	if (!shell)
		exit_error(ERROR_SHELL_NDEF_5, 5);
	if (!shell->cmd)
		exit_error(ERROR_CMD_NDEF_6, 6);
	if (shell->cmd->next == NULL)
		single_cmd(shell, &pid);
	else
	{
		run_pipeline(shell, &pid);
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			shell->exit_code = WEXITSTATUS(status);
		while (wait(NULL) > 0)
			continue ;
	}
	return (free_cmd_list(shell->cmd));
}
