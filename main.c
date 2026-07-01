/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main,c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 17:30:21 by hassmou           #+#    #+#             */
/*   Updated: 2026/07/01 17:52:25 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
    t_env       *env;
	t_tokens	*nodes;
	t_cmd		*cmd;
	char		*line;
	char		**tab;

	nodes = NULL;
	(void)ac;
	(void)av;
	while (1)
	{
		line = readline("My_SHELL> ");
		if (!line)
		{
			printf("exit\n");
			break ;
		}
        env = env_init(envp);
		tab = split_star(line, env);
		nodes = manage_token(tab);
		print_lst(nodes);
		cmd = create_cmd_struct(nodes);
		put_cmd(cmd);
	}
	free(line);
	rl_clear_history();
	return (0);
}