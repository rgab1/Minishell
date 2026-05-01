/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 18:32:09 by grivault          #+#    #+#             */
/*   Updated: 2026/05/01 02:59:43 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <environment.h>

int	del_env_node(t_env **head, char *key)
{
	t_env	*temp;
	t_env	*prev;
	size_t	length;

	if (!head || !*head || !key)
		return (1);
	temp = *head;
	length = ft_strlen(key);
	if (ft_strncmp(temp->key, key, length + 1) == 0)
	{
		*head = temp->next;  // Shift the head pointer to the next node
		return (free_env_node(temp), 0);
	}
	while (temp)
	{
		if (ft_strncmp(temp->key, key, length + 1) == 0)
		{
			prev->next = temp->next;
			return (free_env_node(temp), 0);
		}
		prev = temp;       // Save the current node as 'prev' before moving on
		temp = temp->next; // Advance to the next node
	}
	return (0);
}

void	new_env_node(t_env **head, char	**key_and_value)
{
	t_env	*current;
	t_env	*temp;

	current = (t_env *)malloc(sizeof(t_env));
	if (!current)
		return ;
	current->key = key_and_value[0];
	current->value = key_and_value[1];
	current->next = NULL;
	free(key_and_value);
	if (!*head)
		*head = current;
	else
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = current;
	}
}

t_env	*env_init(char **envp)
{
	t_env	*head;
	size_t	i;

	i = 0;
	head = NULL;
	while (envp[i])
		new_env_node(&head, ft_split(envp[i++], '='));
	return (head);
}
