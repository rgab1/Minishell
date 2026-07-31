/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 19:16:18 by hassmou           #+#    #+#             */
/*   Updated: 2026/07/31 05:20:43 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	manage_fd(t_tokens **tokens, t_cmd *cmd, size_t redir, int i_heredoc)
{
	if (((*tokens)->type == redir) && ((redir == REDIR_IN)
			|| (redir == REDIR_OUT)))
	{
		if(change_fd_redir(tokens, cmd) == -1)
			return (-1);
	}
	else if ((*tokens)->type == redir && (redir == AREDIR_OUT))
	{
		if(change_fd_aredir_out(tokens, cmd) == -1)
			return (-1);
	}
	else if ((*tokens)->type == redir && (redir == HREDIR_IN))
	{
		if (change_fd_hredir_in(tokens, cmd, i_heredoc) == -1)
			return (-1);
	}
	if (cmd->in_fd == -1 || cmd->out_fd == -1)
	{
		perror((*tokens)->data);
		return (-1);
	}
	return (0);
}

int    change_fd_redir(t_tokens **tokens, t_cmd *cmd)
{
    *tokens = (*tokens)->next;
	if (*tokens == NULL || (*tokens)->type != WORD)
		return (minishell_error(ERROR_SYNTAXE, NULL), 1); 
	if ((*tokens)->type == REDIR_IN && cmd->in_fd != -2)
	{
		close(cmd->in_fd);
		cmd->in_fd = -2;
		cmd->in_fd = open((*tokens)->data, O_RDONLY);
	}
	else if ((*tokens)->type == REDIR_OUT && cmd->out_fd != -2)
	{
		close(cmd->out_fd);
		cmd->out_fd = -2;
		cmd->out_fd = open((*tokens)->data, O_WRONLY, O_CREAT, O_TRUNC, 0644);
	}
    return (0);
}

int    change_fd_aredir_out(t_tokens **tokens, t_cmd *cmd)
{
    *tokens = (*tokens)->next;
	if (*tokens == NULL || (*tokens)->type != WORD)
		return (minishell_error(ERROR_SYNTAXE, NULL), 1);
    if (cmd->out_fd != -2)
	{
		close(cmd->out_fd);
		cmd->out_fd = -2;
	}
    cmd->out_fd = open((*tokens)->data, O_WRONLY | O_CREAT | O_APPEND, 0644);
    return (0);
}

int		change_fd_hredir_in(t_tokens **tokens, t_cmd *cmd, int i_heredoc)
{
	char	*namefile;

	if (*tokens == NULL || (*tokens)->type != WORD)
		return (minishell_error(ERROR_SYNTAXE, NULL), 1);
	if (cmd->in_fd != -2)
	{
		close(cmd->out_fd);
		cmd->in_fd = -2;
	}
	namefile = name_file_hc(i_heredoc);
	cmd->in_fd = open(namefile, O_WRONLY, O_CREAT, O_TRUNC, 0644);
	make_heredoc(tokens, cmd);
	close(cmd->out_fd);
	cmd->in_fd = open((*tokens)->data, O_RDONLY);
	unlink(namefile);
	return (0);
}
