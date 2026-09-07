/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_fd_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhalmi <hrhalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 05:06:57 by hassmou           #+#    #+#             */
/*   Updated: 2026/09/07 03:46:45 by hrhalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	make_heredoc(t_tokens **tokens, t_cmd *cmd)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (line == NULL)
		{
			minishell_error(ERROR_CTRL_D_HEREDOC, (*tokens)->data);
			return (0);
		}
		if (g_signal_status != 0)
		{
			free(line);
			return (-1);
		}
		else if (ft_strcmp(line, (*tokens)->data) == 0)
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, cmd->in_fd);
		ft_putchar_fd('\n', cmd->in_fd);
		free(line);
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
