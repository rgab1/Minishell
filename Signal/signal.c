/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 04:21:47 by hassmou           #+#    #+#             */
/*   Updated: 2026/08/06 17:32:55 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigint_handler(int sig)
{
	g_signal_status = 128 + sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	check_g_status(t_shell *shell)
{
	if (g_signal_status != 0)
	{
		shell->exit_code = g_signal_status;
		g_signal_status = 0;
	}
}
