/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_fd_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhalmi <hrhalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 05:06:57 by hassmou           #+#    #+#             */
/*   Updated: 2026/09/11 19:02:58 by hrhalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	make_heredoc(t_tokens **tokens, t_shell *shell)
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
			return (minishell_error("warning", ERROR_CTRL_D_HEREDOC,
				(*tokens)->data), 0);
		}
		else if (ft_strcmp(line, (*tokens)->data) == 0)
		{
			free(line);
			signal(SIGINT, sigint_handler);
			break ;
		}
		manage_expand_heredc(tokens, shell, line);
	}
	return (0);
}

void	manage_expand_heredc(t_tokens **tokens, t_shell *shell, char *line)
{
	t_tokens	token_leurre;

	if ((*tokens)->was_quotes == 0)
	{
		token_leurre.data = line;
		token_leurre.type = WORD;
		token_leurre.was_quotes = 0;
		token_leurre.next = NULL;
		manage_expand(&token_leurre, shell);
		ft_putstr_fd(token_leurre.data, shell->cmd->in_fd);
		ft_putchar_fd('\n', shell->cmd->in_fd);
		free(token_leurre.data);
	}
	else
	{
		ft_putstr_fd(line, shell->cmd->in_fd);
		ft_putchar_fd('\n', shell->cmd->in_fd);
		free(line);
	}
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
