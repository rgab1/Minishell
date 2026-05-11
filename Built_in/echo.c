/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 03:04:57 by grivault          #+#    #+#             */
/*   Updated: 2026/05/11 03:09:33 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	is_n_flag(char *arg)
{
	int	i;

	if (!arg || arg[0] != '-' || arg[1] != 'n')
		return (0);
	i = 1;
	while (arg[i])
	{
		if (arg[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	echo(t_shell *shell)
{
	int	i;
	int	n_flag;

	i = 1;
	n_flag = 0;
	while (shell->cmd->cmd[i] && is_n_flag(shell->cmd->cmd[i]))
	{
		n_flag = 1;
		i++;
	}
	while (shell->cmd->cmd[i])
	{
		ft_putstr_fd(shell->cmd->cmd[i], 1);
		if (shell->cmd->cmd[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (!n_flag)
		ft_putchar_fd('\n', 1);
	return (0);
}
