/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 17:34:10 by grivault          #+#    #+#             */
/*   Updated: 2026/09/11 18:35:19 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_exit(t_shell *shell)
{
	long long	exit_code;
	int			error;

	error = 0;
	exit_code = shell->exit_code;
	if (shell->save_in != -2)
		ft_putstr_fd("exit\n", 2);
	if (shell->cmd->cmd[1])
	{
		exit_code = ft_atoll_safe(shell->cmd->cmd[1], &error);
		if (error == 1)
		{
			minishell_error("exit", ERROR_NUM_ARG, shell->cmd->cmd[1]);
			(full_cleanup(shell), exit(2));
		}
		if (shell->cmd->cmd[2])
		{
			minishell_error("exit", ERROR_MANY_ARGS, NULL);
			return (1);
		}
	}
	return (full_cleanup(shell), exit(exit_code), 0);
}
