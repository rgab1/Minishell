/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 15:58:41 by hassmou           #+#    #+#             */
/*   Updated: 2026/06/14 16:35:55 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "pipex.h"

int	exit_free(t_tokens *token, t_cmd *cmd, char *str)
{
    if (str)
        printf("%s\n", str);
    if (token)
	    free_tokens(token);
    if (cmd)
	    free_cmd(cmd);
	return (-1);
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
			free(cmd);
			cmd = temp_cmd;
		}
		free(cmd->cmd);
		free(cmd);
	}
}
