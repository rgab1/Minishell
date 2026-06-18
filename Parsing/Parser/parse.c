/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 21:46:40 by hassmou           #+#    #+#             */
/*   Updated: 2026/06/16 18:12:13 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "pipex.h"

// static t_cmd	*init_cmd(int len_tok)
// {
// 	t_cmd	*node;

// 	node = malloc(sizeof(t_cmd));
// 	if (!node)
// 		return (NULL);
// 	node->cmd = malloc(sizeof(char *) * (len_tok + 1));
// 	if (!node->cmd)
// 		return (NULL);
// 	node->in_fd = -2;
// 	node->out_fd = -2;
// 	node->next = NULL;
// 	return (node);
// }

// t_cmd	*create_cmd_struct(t_tokens *nodes)
// {
// 	int		j_tab;
// 	t_cmd	*cmd;
// 	t_cmd	*tmp;

// 	j_tab = 0;
// 	while (nodes)
// 	{
// 		if (j_tab == 0)
// 		{
// 			cmd = init_cmd(ft_tokensize(nodes));
// 			if (cmd == NULL)
// 				return (exit_free(nodes, cmd, NULL), NULL);// gestion erreur wip
// 			tmp = cmd;
// 		}
// 		else
// 			if (manage_pipe(&nodes, &cmd, &j_tab) == -1)
//                 return (NULL);
// 		cmd = manage_cmd(&nodes, cmd, &j_tab);
// 		if (cmd == NULL)
// 			return (exit_free(nodes, cmd, NULL), NULL);// gestion erreur wip
// 	}
// 	cmd->cmd[j_tab] = NULL;
// 	return (tmp);
// }

// int	manage_pipe(t_tokens **nodes, t_cmd **cmd, int *j_tab)
// {
// 	if ((*nodes)->type == PIPE)
// 	{
// 		(*nodes) = (*nodes)->next;
//         (*cmd)->cmd[*j_tab] = NULL;
// 		*j_tab = 0;
// 		(*cmd)->next = init_cmd(ft_tokensize((*nodes)));
// 		if ((*cmd) == NULL)
// 			return (exit_free(*nodes, *cmd, NULL), -1);
// 		(*cmd) = (*cmd)->next;
// 	}
// 	else
// 	{
// 		(*cmd)->next = init_cmd(ft_tokensize((*nodes)));
//         if ((*cmd) == NULL)
// 			return (exit_free(*nodes, *cmd, NULL), -1);
// 		(*cmd) = (*cmd)->next;
// 	}
// }

// t_cmd	*manage_cmd(t_tokens **tokens, t_cmd *cmd, int *j_tab)
// {
// 	while (*tokens && (*tokens)->type != PIPE)
// 	{
// 		if ((*tokens)->type == WORD)
// 		{
// 			add_str(tokens, cmd, j_tab);
// 			*tokens = (*tokens)->next;
// 		}
// 		else if ((*tokens)->type == REDIR_IN)
// 		{
// 			if (change_fd(tokens, cmd, REDIR_IN) == -1)
// 				return (exit_free(*tokens, cmd, NULL), NULL);
// 			if (tokens == NULL)
// 				return (exit_free(*tokens, cmd, NULL), NULL);
// 			*tokens = (*tokens)->next;
// 		}
// 		else if ((*tokens)->type == REDIR_OUT)
// 		{
// 			if (change_fd(tokens, cmd, REDIR_OUT) == -1)
// 				return (exit_free(*tokens, cmd, NULL), NULL);
// 			if (tokens == NULL)
// 				return (exit_free(*tokens, cmd, NULL), NULL);
// 			*tokens = (*tokens)->next;
// 		}
// 	}
// 	return (cmd);
// }

// int	change_fd(t_tokens **tokens, t_cmd *cmd, int redir)
// {
// 	if ((*tokens)->next == NULL || (*tokens)->next->data == NULL)
// 		return (-1);
// 	if (((*tokens)->type == redir) && (redir == REDIR_IN))
// 	{
// 		*tokens = (*tokens)->next;
// 		if (cmd->out_fd != -2)
// 			cmd->out_fd = -2;
// 		cmd->in_fd = open((*tokens)->data, O_RDONLY);
// 	}
// 	else if ((*tokens)->type == redir && (redir == REDIR_OUT))
// 	{
// 		*tokens = (*tokens)->next;
// 		if (cmd->in_fd != -2)
// 			cmd->in_fd = -2;
// 		cmd->out_fd = open((*tokens)->data, O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	}
// 	if (cmd->in_fd == -1 || cmd->out_fd == -1)
// 	{
// 		perror((*tokens)->data);
// 		return (-1);
// 	}
// 	return (0);
// }

////////////////////////////////////////////

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
	while (nodes)
	{
		if (j_tab == 0)
		{
			cmd = init_cmd(ft_tokensize(nodes));
			if (cmd == NULL)
				return (exit_free(nodes, cmd, NULL), NULL);// gestion erreur wip
			tmp = cmd;
		}
		else
			if (manage_pipe(&nodes, &cmd, &j_tab) == -1)
                return (NULL);
		if (nodes)
            printf("[DEBUG CREATE] Avant manage_cmd | j_tab = %d | token actuel = %s\n", j_tab, nodes->data);
		cmd = manage_cmd(&nodes, cmd, &j_tab);
		if (cmd == NULL)
			return (exit_free(nodes, cmd, NULL), NULL);// gestion erreur wip
	}
	return (tmp);
}

int	manage_pipe(t_tokens **nodes, t_cmd **cmd, int *j_tab)
{
	if (*nodes)
        printf("[DEBUG PIPE] Entrée | j_tab = %d | token = %s\n", *j_tab, (*nodes)->data);
	if ((*nodes)->type == PIPE)
	{
		(*nodes) = (*nodes)->next;
        (*cmd)->cmd[*j_tab] = NULL;
		*j_tab = 0;
		printf("[DEBUG PIPE] -> Index j_tab réinitialisé à %d\n", *j_tab);
		(*cmd)->next = init_cmd(ft_tokensize((*nodes)));
		if ((*cmd) == NULL)
			return (exit_free(*nodes, *cmd, NULL), -1);
		(*cmd) = (*cmd)->next;
	}
	else
	{
		(*cmd)->next = init_cmd(ft_tokensize((*nodes)));
        if ((*cmd) == NULL)
			return (exit_free(*nodes, *cmd, NULL), -1);
		(*cmd) = (*cmd)->next;
	}
}

t_cmd	*manage_cmd(t_tokens **tokens, t_cmd *cmd, int *j_tab)
{
	while (*tokens && (*tokens)->type != PIPE)
	{
		if (*tokens)
            printf("[DEBUG CMD] Evaluation | type = %d | token = %s\n", (*tokens)->type, (*tokens)->data);
		if ((*tokens)->type == WORD)
		{
			printf("[DEBUG WORD] -> Ajout du mot '%s' à l'index %d\n", (*tokens)->data, *j_tab);
			add_str(tokens, cmd, j_tab);
			*tokens = (*tokens)->next;
		}
		else if ((*tokens)->type == REDIR_IN)
		{
			if (change_fd(tokens, cmd, REDIR_IN) == -1)
				return (exit_free(*tokens, cmd, NULL), NULL);
			if (tokens == NULL)
				return (exit_free(*tokens, cmd, NULL), NULL);
			*tokens = (*tokens)->next;
		}
		else if ((*tokens)->type == REDIR_OUT)
		{
			if (change_fd(tokens, cmd, REDIR_OUT) == -1)
				return (exit_free(*tokens, cmd, NULL), NULL);
			if (tokens == NULL)
				return (exit_free(*tokens, cmd, NULL), NULL);
			*tokens = (*tokens)->next;
		}
	}
	return (cmd);
}

int	change_fd(t_tokens **tokens, t_cmd *cmd, int redir)
{
	if ((*tokens)->next == NULL || (*tokens)->next->data == NULL)
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
