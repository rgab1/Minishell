/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:47:53 by grivault          #+#    #+#             */
/*   Updated: 2026/06/18 20:18:34 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pipex.h>

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
	free_split(current->cmd);
	free(current);
}

void	free_envp(char **envp)
{
	free_split(envp);
}

void	free_list(t_cmd *head)
{
	t_cmd	*tmp;

	while (head)
	{
		tmp = head->next;
		free_split(head->cmd);
		free(head);
		head = tmp;
	}
}
