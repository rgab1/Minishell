/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 21:46:40 by hassmou           #+#    #+#             */
/*   Updated: 2026/06/14 11:06:33 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "pipex.h"
#include "stdio.h"

static t_cmd	*init_cmd(int len_tok)
{
	t_cmd	*node;

	node = malloc(sizeof(t_cmd));
	if (!node)
		return (NULL);
	node->cmd = malloc(sizeof(char *) * (len_tok + 1));
	if (!node->cmd)
		return (NULL);
	node->in_fd = -2;
	node->out_fd = -2;
	node->next = NULL;
	return (node);
}

t_cmd	*create_cmd_struct(t_tokens *nodes)
{
	int		j_tab;
	t_cmd	*cmd;
	t_cmd	*tmp;

	j_tab = 0;
	cmd = malloc(sizeof(t_cmd) + 1);
	if (!cmd)
		return (NULL);
	while (nodes)
	{
		if (j_tab == 0)
		{
			cmd = init_cmd(ft_tokensize(nodes));
			tmp = cmd;
		}
		else
			manage_pipe(&cmd, &nodes);
		cmd = manage_cmd(&nodes, cmd, &j_tab);
		if (cmd == NULL)
			return (NULL);
	}
	return (tmp);
}

void	manage_pipe(t_cmd **cmd, t_tokens **nodes)
{
	if ((*nodes)->type == PIPE)
	{
		(*nodes) = (*nodes)->next;
		(*cmd)->next = init_cmd(ft_tokensize((*nodes)));
		(*cmd) = (*cmd)->next;
	}
	else
	{
		(*cmd)->next = init_cmd(ft_tokensize((*nodes)));
		(*cmd) = (*cmd)->next;
	}
}

t_cmd	*manage_cmd(t_tokens **tokens, t_cmd *cmd, int *j_tab)
{
	while (*tokens && (*tokens)->type != PIPE)
	{
		if ((*tokens)->type == WORD)
		{
			add_str(tokens, cmd, j_tab);
			*tokens = (*tokens)->next;
		}
		else if ((*tokens)->type == REDIR_IN)
		{
			change_fd(tokens, cmd, REDIR_IN);
			if (tokens == NULL)
				return (NULL);
			*tokens = (*tokens)->next;
		}
		else if ((*tokens)->type == REDIR_OUT)
		{
			change_fd(tokens, cmd, REDIR_OUT);
			if (tokens == NULL)
				return (NULL);
			*tokens = (*tokens)->next;
		}
	}
	return (cmd);
}

int	change_fd(t_tokens **tokens, t_cmd *cmd, int redir)
{
	if ((*tokens)->next == NULL || (*tokens)->next->data == NULL)
		// appel fonction liberer memoire + putstring
		return (-1);
	if (((*tokens)->type == redir) && (redir == REDIR_IN))
	{
		*tokens = (*tokens)->next;
		if (cmd->out_fd != -2)
			cmd->out_fd = -2;
		cmd->in_fd = open((*tokens)->data, O_RDONLY);
	}
	else if ((*tokens)->type == redir && (redir == REDIR_OUT))
	{
		*tokens = (*tokens)->next;
		if (cmd->in_fd != -2)
			cmd->in_fd = -2;
		cmd->out_fd = open((*tokens)->data, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	if (cmd->in_fd == -1 || cmd->out_fd == -1)
	{
		perror((*tokens)->data);
		return (-1);
	}
	return (0);
}
