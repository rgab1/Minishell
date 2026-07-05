/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 17:34:10 by grivault          #+#    #+#             */
/*   Updated: 2026/07/05 23:50:48 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

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
	int	exit_code;

	ft_putstr_fd("exit\n", 2);
	if (shell->cmd->cmd[1])
	{
		if (!is_numeric(shell->cmd->cmd[1]))
		{
			numeric_error_print(shell->cmd->cmd[1]);
			full_cleanup(shell);
			exit(255);
		}
		if (shell->cmd->cmd[2])
		{
			minishell_error("exit", ERROR_MANY_ARGS);
			return (1);
		}
		shell->exit_code = ft_atoi(shell->cmd->cmd[1]);
	}
	exit_code = shell->exit_code;
	full_cleanup(shell);
	return (exit(exit_code), 0);
}
