/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhalmi <hrhalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 01:15:50 by grivault          #+#    #+#             */
/*   Updated: 2026/08/22 06:26:08 by hrhalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	free_env_node(t_env *node)
{
	if (node)
	{
		if (node->key)
			free(node->key);
		if (node->value)
			free(node->value);
		free(node);
	}
}

void	free_env(t_env *head)
{
	t_env	*temp;

	if (!head)
		return ;
	while (head)
	{
		temp = head->next;
		free_env_node(head);
		head = temp;
	}
}
