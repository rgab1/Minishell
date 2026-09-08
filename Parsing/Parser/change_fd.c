/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhalmi <hrhalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 19:16:18 by hassmou           #+#    #+#             */
/*   Updated: 2026/09/08 21:25:21 by hrhalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	manage_fd(t_tokens **tokens, t_shell *shell, int *i_heredoc)
{
	if (((*tokens)->type == REDIR_IN) || (*tokens)->type == REDIR_OUT)
	{
		if (change_fd_redir(tokens, (*tokens)->type, shell->cmd) == -1)
			return (-1);
	}
	else if ((*tokens)->type == AREDIR_OUT)
	{
		if (change_fd_aredir_out(tokens, shell->cmd) == -1)
			return (-1);
	}
	else if ((*tokens)->type == HREDIR_IN)
	{
		if (change_fd_hredir_in(tokens, shell, i_heredoc) == -1)
			return (-1);
	}
	if (shell->cmd->in_fd == -1 || shell->cmd->out_fd == -1)
	{
		perror((*tokens)->data);
	}
	return (0);
}

int	change_fd_redir(t_tokens **tokens, size_t redir, t_cmd *cmd)
{
	*tokens = (*tokens)->next;
	if (*tokens == NULL || (*tokens)->data == NULL || (*tokens)->type != WORD)
		return (minishell_error(ERROR_SYNTAXE, NULL), -1);
	if (redir == REDIR_IN)
	{
		if (cmd->in_fd != -2)
		{
			close(cmd->in_fd);
			cmd->in_fd = -2;
		}
		cmd->in_fd = open((*tokens)->data, O_RDONLY);
	}
	else if (redir == REDIR_OUT)
	{
		if (cmd->out_fd != -2)
		{
			close(cmd->out_fd);
			cmd->out_fd = -2;
		}
		cmd->out_fd = open((*tokens)->data, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	return (0);
}

int	change_fd_aredir_out(t_tokens **tokens, t_cmd *cmd)
{
	*tokens = (*tokens)->next;
	if (*tokens == NULL || (*tokens)->data == NULL || (*tokens)->type != WORD)
		return (minishell_error(ERROR_SYNTAXE, NULL), -1);
	if (cmd->out_fd != -2)
	{
		close(cmd->out_fd);
		cmd->out_fd = -2;
	}
	cmd->out_fd = open((*tokens)->data, O_WRONLY | O_CREAT | O_APPEND, 0644);
	return (0);
}

int	change_fd_hredir_in(t_tokens **tokens, t_shell *shell, int *i_heredoc)
{
	char	*namefile;

	*tokens = (*tokens)->next;
	if (*tokens == NULL || (*tokens)->type != WORD)
		return (minishell_error(ERROR_SYNTAXE, NULL), -1);
	if (shell->cmd->in_fd != -2)
	{
		close(shell->cmd->in_fd);
		shell->cmd->in_fd = -2;
	}
	namefile = name_file_hc(i_heredoc);
	(*i_heredoc)++;
	shell->cmd->in_fd = open(namefile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (shell->cmd->in_fd == -1)
	{
		unlink(namefile);
		perror(namefile);
		free(namefile);
	}
	if (change_heredoc_extension(tokens, shell, namefile) == -1)
		return (-1);
	return (0);
}

int	change_heredoc_extension(t_tokens **tokens, t_shell *shell, char *namefile)
{
	if (make_heredoc(tokens, shell) == -1)
	{
		close(shell->cmd->in_fd);
		shell->cmd->in_fd = -2;
		unlink(namefile);
		free(namefile);
		return (-1);
	}
	close(shell->cmd->in_fd);
	shell->cmd->in_fd = open(namefile, O_RDONLY);
	unlink(namefile);
	free(namefile);
	return (0);
}
