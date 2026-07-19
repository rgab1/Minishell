/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 21:46:40 by hassmou           #+#    #+#             */
/*   Updated: 2026/07/19 22:10:10 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_cmd	*init_cmd(int len_tok)
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
	node->namefile = NULL;
	node->next = NULL;
	return (node);
}

t_cmd	*create_cmd_struct(t_tokens *nodes)
{
	int		j_tab;
	t_cmd	*cmd;
	t_cmd	*tmp;

	j_tab = 0;
	while (nodes)
	{
		if (j_tab == 0)
		{
			cmd = init_cmd(ft_tokensize(nodes));
			if (cmd == NULL)
				return (NULL);// gestion erreur wip
			tmp = cmd;
		}
		else
			if (manage_pipe(&nodes, &cmd, &j_tab) == -1)
                return (NULL);
		cmd = manage_cmd(&nodes, cmd, &j_tab);
		if (cmd == NULL)
			return (NULL);// gestion erreur wip
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
		if ((*cmd) == NULL)
			return (-1);
		(*cmd) = (*cmd)->next;
	}
	else
	{
		(*cmd)->next = init_cmd(ft_tokensize((*nodes)));
        if ((*cmd) == NULL)
			return (-1);
		(*cmd) = (*cmd)->next;
	}
	return (0);
}

// 			*tokens = (*tokens)->next;
t_cmd	*manage_cmd(t_tokens **tokens, t_cmd *cmd, int *j_tab)
{
	while (*tokens && (*tokens)->type != PIPE)
	{
		if ((*tokens)->type == WORD)
			{
				manage_expand();
				add_str(tokens, cmd, j_tab);
			}
		else
		{
			if (sort_redir(tokens, cmd) == -1)
			return (NULL); 
		}
		*tokens = (*tokens)->next;
	}
	return (cmd);
}

int	sort_redir(t_tokens **tokens, t_cmd *cmd)
{
	if (((*tokens)->type == REDIR_IN) 
			|| ((*tokens)->type == REDIR_OUT) 
				|| ((*tokens)->type == AREDIR_OUT))
	{
		if ((*tokens)->next == NULL || (*tokens)->next->data == NULL)
			return (-1); //  gestion d'erreur a faire
		if (manage_fd(tokens, cmd, (*tokens)->type) == -1)
			return (-1);//  gestion d'erreur a faire
		// *tokens = (*tokens)->next;
	}
	// else if ((*tokens)->type == HREDIR_IN)
	// {
		// if (manage_fd(tokens, cmd, HREDIR_IN) == -1)
			// return (-1);
	// }  POUR HEREDOC A FAIRE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
	return (0);
}
