/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 13:49:40 by grivault          #+#    #+#             */
/*   Updated: 2026/08/06 16:50:06 by hassmou          ###   ########.fr       */
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
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		run_command(shell->cmd, get_envp(shell), shell);
	}
	waitpid(*pid, &status, 0);
	if (WIFEXITED(status))
		shell->exit_code = WEXITSTATUS(status);
	if (WIFSIGNALED(status))
		shell->exit_code = 128 + WTERMSIG(status);
}

void	execution(t_shell *shell)
{
	int	pid;
	int	status;

	if (!shell)
		exit_error(ERROR_SHELL_NDEF_5, 5);
	if (!shell->cmd)
		exit_error(ERROR_CMD_NDEF_6, 6);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	if (shell->cmd->next == NULL)
		single_cmd(shell, &pid);
	else
	{
		run_pipeline(shell, &pid);
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			shell->exit_code = WEXITSTATUS(status);
		if (WIFSIGNALED(status))
			shell->exit_code = 128 + WTERMSIG(status);
		while (wait(NULL) > 0)
			continue ;
	}
	signal(SIGINT, sigint_handler);
	free_cmd_struct(shell->cmd);
	shell->cmd = NULL;
}
