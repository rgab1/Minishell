/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:47:53 by grivault          #+#    #+#             */
/*   Updated: 2026/08/06 16:28:58 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	free_cmd(t_cmd *current)
{
	if (!current)
		return ;
	if (current->cmd)
		free_split(current->cmd);
	if (current->in_fd > 2)
	{
		close(current->in_fd);
		current->in_fd = -1;
	}
	if (current->out_fd > 2)
	{
		close(current->out_fd);
		current->out_fd = -1;
	}
	if (current)
		free(current);
}

void	free_envp(char **envp)
{
	if (envp)
		free_split(envp);
}

void	free_cmd_list(t_cmd *head)
{
	t_cmd	*tmp;

	while (head)
	{
		tmp = head->next;
		free_cmd(head);
		head = tmp;
	}
}
