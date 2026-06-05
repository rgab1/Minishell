/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 21:46:40 by hassmou           #+#    #+#             */
/*   Updated: 2026/06/05 14:21:02 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "pipex.h"

int	ft_tokensize(t_tokens *lst)
{
	int	len;

	len = 0;
	while (lst != NULL && lst->type != PIPE)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

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
    int     j_tab;
	t_cmd	*cmd;

    j_tab = 0;
	cmd = malloc(sizeof(t_cmd) + 1);
	if (!cmd)
		return (NULL);
	while (nodes)
	{
		if (j_tab == 0)
        cmd = init_cmd(ft_tokensize(nodes));
        if (nodes->type == PIPE)
            nodes = nodes->next;
        else
        {
			cmd->next = init_cmd(ft_tokensize(nodes));
		    cmd = cmd->next;
        }
        cmd = manage_cmd(nodes, cmd, &j_tab);
        if (cmd == NULL)
            return (NULL);
	}
	return (cmd);
}
    
t_cmd *manage_cmd(t_tokens *tokens, t_cmd *cmd, int *j_tab)
{
    while (tokens->type != PIPE && !tokens)
    {
        if (tokens->type == WORD)
        {
            if (add_str(tokens, cmd, j_tab) == -1)
                return (NULL);
        }
        else if (tokens->type == REDIR_IN)
        {
            tokens = change_fd(tokens, cmd, REDIR_IN);
            if (tokens == NULL)
                return (NULL);
        }
        else if (tokens->type == REDIR_OUT)
        {
            tokens = change_fd(tokens, cmd, REDIR_OUT);
            if (tokens == NULL)
                return (NULL);
        }
    }
}

int    add_str(t_tokens *tokens, t_cmd *cmd, int *j_tab)
{
    int size;

    size = strlen(tokens->data);
    cmd->cmd[*j_tab] = tokens->data;
    *j_tab ++;
    return (0);
}

t_tokens	*change_fd(t_tokens *tokens, t_cmd *cmd, int redir)
{
	if (tokens->next == NULL)
		// appel fonction liberer memoire + putstring
		return (NULL);
    if (tokens->next->data == NULL)
		// appel fonction liberer memoire + putstring
		return (NULL);
	if (tokens->type == redir)
    {
        tokens = tokens->next;
		cmd->in_fd = open(tokens->data, O_RDONLY);
    }
	else if (tokens->type == redir)
	{
        tokens = tokens->next;
        cmd->out_fd = open(tokens->data, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    }
    if (cmd->in_fd == -1 || cmd->out_fd == -1)
    {
        perror(tokens->data);
        return (NULL);
    }
	tokens = tokens->next;
    return (tokens); 
}
/* il faut gerer le cas ou on avait deja modifier les in/out _fd 
et reverifier derriere */   