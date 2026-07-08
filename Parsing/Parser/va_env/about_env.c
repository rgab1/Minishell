/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:36:49 by hassmou           #+#    #+#             */
/*   Updated: 2026/07/07 07:08:35 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	count_va_env(const char *str, size_t *i, t_env *env, size_t *supp)
{
	size_t	cost_value;
	size_t	start_key;
	char	*key;

	if (!((str[(*i) + 1] >= 65 && str[(*i) + 1] <= 90) || (str[(*i) + 1] >= 97
				&& str[(*i) + 1] <= 122) && (str[(*i) + 1] == '_')))
		{
			(*i)++;
			return (0);
		}
	start_key = (*i);
	start_key++;
	while (((str[start_key] >= 48 && str[start_key] <= 57)
			|| (str[start_key] >= 65 && str[start_key] <= 90)
			|| (str[start_key] >= 97 && str[start_key] <= 122)
			|| (str[start_key] == '_')))
		start_key++;
	key = ft_substr(str, (unsigned int)(*i), start_key - (*i));
	(*i) += start_key - (*i);
	printf("key = %s, len = %d\n", key, ft_strlen(key));
	printf("supp = %d\n", (*supp));
	(*supp) += ft_strlen(key);
	printf("supp + %d = %d\n", ft_strlen(key), (*supp));
	cost_value = ft_strlen(get_value(key + 1, env));
	printf("cost_value = %d\n", cost_value);
	free(key);
	return (cost_value);
}

char	*get_key(unsigned char *src, t_env *env, int *i)
{
	size_t	j;
	char	*key;

	j = 0;
	if ((src[(*i) + 1] >= 65 && src[(*i) + 1] <= 90) || (src[(*i) + 1] >= 97
			&& src[(*i) + 1] <= 122) || (src[(*i) + 1] == '_'))
		key[j] = src[(*i)];
	else
		return (NULL);
	while (ft_is_env(src[(*i) + 1]))
	{
		(*i)++;
		j++;
		key[j] = src[(*i)];
	}
	if (!ft_is_key(key, env))
		return (NULL);
	return (key);
}

int	ft_is_key(char *key, t_env *head)
{
	size_t	key_len;

	*key++;
	key_len = ft_strlen(key);
	while (head)
	{
		if (ft_strncmp(key, head->key, key_len + 1))
			return (0);
		head = head->next;
	}
	return (1);
}

int	ft_is_env(char c)
{
	if (((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122)
			|| (c == '_')))
		return (0);
	else
		return (1);
}
