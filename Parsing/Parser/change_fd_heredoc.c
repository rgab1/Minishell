/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_fd_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhalmi <hrhalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 05:06:57 by hassmou           #+#    #+#             */
/*   Updated: 2026/09/08 03:24:13 by hrhalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	make_heredoc(t_tokens **tokens, t_cmd *cmd)
{
	char	*line;

	signal(SIGINT, sigint_heredoc_handler);
	while (1)
	{
		line = readline("> ");
		if (line == NULL)
		{
			if (line_null_by_sigint_heredc(line) == -1)
				return (-1);
			signal(SIGINT, sigint_handler);
			return (minishell_error(ERROR_CTRL_D_HEREDOC, (*tokens)->data), 0);
		}
		else if (ft_strcmp(line, (*tokens)->data) == 0)
		{
			free(line);
			signal(SIGINT, sigint_handler);
			break ;
		}
		ft_putstr_fd(line, cmd->in_fd);
		ft_putchar_fd('\n', cmd->in_fd);
		free(line);
	}
	return (0);
}

int	line_null_by_sigint_heredc(char *line)
{
	if (g_signal_status != 0)
	{
		free(line);
		open("/dev/tty", O_RDONLY);
		signal(SIGINT, sigint_handler);
		return (-1);
	}
	return (0);
}

char	*name_file_hc(int *i_heredoc)
{
	char	*nbr_file;
	char	*res;

	nbr_file = ft_itoa(*i_heredoc);
	res = ft_strjoin(".my_heredoc_", nbr_file);
	free(nbr_file);
	return (res);
}
