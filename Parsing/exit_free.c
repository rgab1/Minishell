/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 15:58:41 by hassmou           #+#    #+#             */
/*   Updated: 2026/07/01 18:51:50 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "pipex.h"

void	exit_free(t_tokens *token, t_cmd *cmd, char *str)
{
    if (str)
        printf("%s\n", str);
    if (token)
	    free_tokens(token);
    if (cmd)
	    free_cmd(cmd);
}

void	free_tokens(t_tokens *token)
{
	t_tokens	*temp_tok;

	if (token)
	{
		while (token->next)
		{
			temp_tok = token->next;
			free(token->data);
			free(token);
			token = temp_tok;
		}
		free(token->data);
		free(token);
	}
}

void	free_cmd(t_cmd *cmd)
{
	t_cmd	*temp_cmd;

	if (cmd)
	{
		while (cmd->next)
		{
			temp_cmd = cmd->next;
			free(cmd->cmd);
			if (cmd->namefile)
				free(cmd->namefile);
			if (cmd->in_fd != -2)
				close(cmd->in_fd);
			if (cmd->out_fd != -2)
				close(cmd->out_fd);
			free(cmd);
			cmd = temp_cmd;
		}
		free(cmd->cmd);
		free(cmd);
	}
}
