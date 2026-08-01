/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 21:46:40 by hassmou           #+#    #+#             */
/*   Updated: 2026/08/01 05:55:31 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*init_cmd(int len_tok)
{
	t_cmd	*node;
	int		i;

	i = 0;
	node = malloc(sizeof(t_cmd));
	if (!node)
		return (NULL);
	node->cmd = malloc(sizeof(char *) * (len_tok + 1));
	if (!node->cmd)
		return (NULL);
	while (i <= len_tok)
		node->cmd[i++] = NULL;
	node->in_fd = -2;
	node->out_fd = -2;
	node->namefile = NULL;
	node->next = NULL;
	return (node);
}

t_cmd	*create_cmd_struct(t_tokens *nodes)
{
	int		j_tab;
	int		i_heredoc;
	t_cmd	*cmd;
	t_cmd	*tmp;

	j_tab = 0;
	i_heredoc = 0;
	while (nodes)
	{
		if (j_tab == 0)
		{
			cmd = init_cmd(ft_tokensize(nodes));
			if (cmd == NULL)
				return (NULL);
			tmp = cmd;
		}
		else
			if (manage_pipe(&nodes, &cmd, &j_tab) == -1)
                return (free_cmd_struct(tmp), NULL);
		cmd = manage_cmd(&nodes, cmd, &j_tab, &i_heredoc);
		if (cmd == NULL)
			return (free_cmd_struct(tmp), NULL);
	}
	cmd->cmd[j_tab] = NULL;
	return (tmp);
}

int	manage_pipe(t_tokens **nodes, t_cmd **cmd, int *j_tab)
{
	if ((*nodes)->type == PIPE)
	{
		(*nodes) = (*nodes)->next;
        (*cmd)->cmd[*j_tab] = NULL;
		*j_tab = 0;
		(*cmd)->next = init_cmd(ft_tokensize((*nodes)));
		if ((*cmd)->next == NULL)
			return (-1); //gestion d'erreur a faire
		(*cmd) = (*cmd)->next;
	}
	return (0);
}

t_cmd	*manage_cmd(t_tokens **tokens, t_cmd *cmd, int *j_tab, int *i_heredoc)
{
	while (*tokens && (*tokens)->type != PIPE)
	{
		if ((*tokens)->type == WORD)
				add_str(tokens, cmd, j_tab);
		else
		{
			if (sort_redir(tokens, cmd, i_heredoc) == -1)
				return (NULL); 
		}
		*tokens = (*tokens)->next;
	}
	return (cmd);
}

int	sort_redir(t_tokens **tokens, t_cmd *cmd, int *i_heredoc)
{
	if ((*tokens)->type == REDIR_IN
			|| (*tokens)->type == REDIR_OUT
				|| (*tokens)->type == AREDIR_OUT
					|| (*tokens)->type == HREDIR_IN)
	{
		if ((*tokens)->next == NULL || (*tokens)->next->data == NULL)
			return (minishell_error(ERROR_SYNTAXE, (*tokens)->next->data), -1);
		if (manage_fd(tokens, cmd, i_heredoc) == -1)
			return (-1);
	}	
	return (0);
}
