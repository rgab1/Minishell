/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 19:59:29 by grivault          #+#    #+#             */
/*   Updated: 2026/07/23 07:12:14 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*get_value(char *key, t_env *head)
{
	size_t	key_len;

	key_len = ft_strlen(key);
	while (head)
	{
		if (!ft_strncmp(key, head->key, key_len + 1))
		{
			if (head->value)
				return (head->value);
			else
				return (NULL);
		}
		head = head->next;
	}
	return (NULL);
}
