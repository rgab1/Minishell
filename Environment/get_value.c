/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 19:59:29 by grivault          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/07/06 00:05:17 by grivault         ###   ########.fr       */
=======
/*   Updated: 2026/07/07 03:21:47 by hassmou          ###   ########.fr       */
>>>>>>> origin/Hassan
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
			return (head->value);
		head = head->next;
	}
	return (ft_strdup("")); // gerer l'erreur ou la key n'est pas trouve
}
