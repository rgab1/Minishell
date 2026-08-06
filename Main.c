/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 17:30:21 by hassmou           #+#    #+#             */
/*   Updated: 2026/08/05 21:52:03 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_signal_status = 0;

void	print_lst(t_tokens *nodes)
{
	if (nodes == NULL)
		return ;
	while (nodes->next != NULL)
	{
		printf("content = %s; make type_nbr = %d\n", nodes->data, nodes->type);
		nodes = nodes->next;
	}
	printf("content = %s; type_nbr = %d\n", nodes->data, nodes->type);
}

void	start_minishell(int ac, char **av)
{
	(void)ac;
	(void)av;
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sigint_handler);
}

void	end_of_minishell(t_shell *shell, char *line)
{
	free(line);
	rl_clear_history();
	full_cleanup(shell);
}

int	main(int ac, char **av, char **envp)
{
	t_shell		*shell;
	char		*line;

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
			break;
		}
		check_g_status(shell);
		if (line[0] != '\0')
			add_history(line);
		shell = manage_shell(line, shell);
		if (!shell)
			break ;
		execution(shell);
	}
	end_of_minishell(shell, line);
	return (0);
}
