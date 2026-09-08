/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhalmi <hrhalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 04:21:47 by hassmou           #+#    #+#             */
/*   Updated: 2026/09/08 03:17:48 by hrhalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigint_handler(int sig)
{
	g_signal_status = sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	sigint_heredoc_handler(int sig)
{
	g_signal_status = sig;
	write(1, "\n", 1);
	close(0);
}

void	check_g_status(t_shell *shell)
{
	if (g_signal_status != 0)
	{
		shell->exit_code = g_signal_status + 128;
		g_signal_status = 0;
	}
}
