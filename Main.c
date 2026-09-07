/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhalmi <hrhalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 17:30:21 by hassmou           #+#    #+#             */
/*   Updated: 2026/09/07 05:49:03 by hrhalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		g_signal_status = 0;

void	start_minishell(int ac, char **av)
{
	(void)ac;
	(void)av;
	signal(SIGTSTP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sigint_handler);
}

void	end_of_minishell(t_shell *shell, char *line)
{
	if (line)
		free(line);
	rl_clear_history();
	full_cleanup(shell);
}

void	in_minishell(t_shell *shell, char *line)
{
	check_g_status(shell);
	if (line[0] != '\0')
		add_history(line);
	shell = manage_shell(line, shell);
	if (!shell->cmd)
		return ;
	execution(shell);
}

int	main(int ac, char **av, char **envp)
{
	t_shell	*shell;
	char	*line;

	start_minishell(ac, av);
	shell = shell_init(envp);
	if (!shell)
		return (1);
	while (1)
	{
		line = readline("My_SHELL> ");
		if (!line)
		{
			printf("exit\n");
			break ;
		}
		in_minishell(shell, line);
		free(line);
	}
	end_of_minishell(shell, line);
	return (0);
}
