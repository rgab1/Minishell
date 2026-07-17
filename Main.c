/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 17:30:21 by hassmou           #+#    #+#             */
/*   Updated: 2026/07/17 21:15:15 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_lst(t_tokens *nodes)
{
	if (nodes == NULL)
		return ;
	while (nodes->next != NULL)
	{
		printf("content = %s; type_nbr = %d\n", nodes->data, nodes->type);
		nodes = nodes->next;
	}
	printf("content = %s; type_nbr = %d\n", nodes->data, nodes->type);
}

int	main(int ac, char **av, char **envp)
{
	t_shell		*shell;
	char		*line;

	(void)ac;
	(void)av;
	shell = shell_init();
	while (1)
	{
		line = readline("My_SHELL> ");
		if (!line)
		{
			printf("exit\n");
			return (0);
		}
		shell = manage_shell(envp, line, shell);
		if (!shell)
			return (1);
	}
	free(line);
	rl_clear_history();
	return (0);
}
