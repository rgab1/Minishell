/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 01:15:50 by grivault          #+#    #+#             */
/*   Updated: 2026/05/01 02:09:57 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <environment.h>

void	free_env_node(t_env *node)
{
	if (node)
	{
		free(node->key);
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
