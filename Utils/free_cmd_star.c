/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmd_star.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 16:01:21 by hassmou           #+#    #+#             */
/*   Updated: 2026/08/01 04:17:06 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    free_cmd_struct(t_cmd *cmd)
{
    t_cmd   *tmp;

    if (cmd)
    {
        while (cmd)
        {
            tmp = cmd->next;
            free_cmd_star(cmd);
            cmd = tmp;
        }
    }
}

void	free_cmd_star(t_cmd *cmd)
{
    size_t  i;

    i = 0;
	if (cmd->cmd)
    {
        while (cmd->cmd[i])
        {
            free(cmd->cmd[i]);
            i++;
        }
    }
	if (cmd->namefile)
		free(cmd->namefile);
	if (cmd->in_fd != -2)
		close(cmd->in_fd);
	if (cmd->out_fd != -2)
		close(cmd->out_fd);
	free(cmd);
}
