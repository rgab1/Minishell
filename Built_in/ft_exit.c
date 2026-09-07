/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 17:34:10 by grivault          #+#    #+#             */
/*   Updated: 2026/09/07 22:15:30 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	numeric_error_print(char *arg)
{
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(ERROR_NUM_ARG, 2);
	ft_putstr_fd("\n", 2);
}

int	ft_exit(t_shell *shell)
{
	long long	exit_code;
	int			error;

	error = 0;
	exit_code = shell->exit_code;
	ft_putstr_fd("exit\n", 2);
	if (shell->cmd->cmd[1])
	{
		exit_code = ft_atoll_safe(shell->cmd->cmd[1], &error);
		if (error == 1)
		{
			numeric_error_print(shell->cmd->cmd[1]);
			full_cleanup(shell);
			exit(2);
		}
		if (shell->cmd->cmd[2])
		{
			minishell_error("exit", ERROR_MANY_ARGS);
			return (1);
		}
	}
	full_cleanup(shell);
	return (exit(exit_code), 0);
}
