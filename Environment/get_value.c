/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 19:59:29 by grivault          #+#    #+#             */
/*   Updated: 2026/05/01 20:05:31 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <environment.h>

char *get_value(char *key, t_env *head)
{
	size_t key_len;

	key_len = ft_strlen(key);
	while (head)
	{
		if (!ft_strncmp(key, head->key, key_len + 1))
			return (head->value);
		head = head->next;
	}
	return (NULL); // gerer l'erreur ou la key n'est pas trouve
}
