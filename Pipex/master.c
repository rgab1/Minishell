/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 13:49:40 by grivault          #+#    #+#             */
/*   Updated: 2026/07/03 18:33:40 by grivault         ###   ########.fr       */
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

void	master_function(t_shell *shell)
{
	int	pid;
	int	status;

	if (!shell || !shell->cmd)
		return (exit_error("Shell not defined", 4));
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
	return (full_cleanup(shell));
}
