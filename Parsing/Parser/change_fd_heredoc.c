/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_fd_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 05:06:57 by hassmou           #+#    #+#             */
/*   Updated: 2026/08/01 04:33:46 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	make_heredoc(t_tokens **tokens, t_cmd *cmd)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (line == NULL)
		{
			minishell_error(ERROR_CTRL_D_HEREDOC, (*tokens)->data);
			break;
		}
		else if (ft_strcmp(line, "EOF") == 0)
		{
			free(line);
			break;
		}
		ft_putstr_fd(line, cmd->in_fd);
		ft_putchar_fd('\n', cmd->in_fd);
	}
}

char	*name_file_hc(int i_heredoc)
{
	char	*nbr_file;

	nbr_file = ft_itoa(i_heredoc);
	return (ft_strjoin(".heredoc_", nbr_file));
}