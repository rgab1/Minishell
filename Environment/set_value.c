/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 19:59:29 by grivault          #+#    #+#             */
/*   Updated: 2026/05/02 20:22:38 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <environment.h>

static char	**key_and_value_pair(char *key, char *value)
{
	char	**pair;

	pair = (char **)malloc(sizeof(char *) * 3);
	if (!pair)
		return (NULL);
	pair[0] = ft_strdup(key);
	pair[1] = ft_strdup(value);
	pair[2] = NULL;
	return (pair);
}

int	set_value(char *key, char *value,  t_env **head)
{
	size_t	key_len;
	t_env	*temp;

	if (!head)
		return (1);
	temp = *head;
	key_len = ft_strlen(key);
	while (temp)
	{
		if (!ft_strncmp(key, temp->key, key_len + 1))
		{
			free(temp->value);
			temp->value = ft_strdup(value);
			return (0);
		}
		temp = temp->next;
	}
	new_env_node(head, key_and_value_pair(key, value));
	return (0);
}
