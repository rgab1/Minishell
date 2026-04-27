/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 21:04:26 by grivault          #+#    #+#             */
/*   Updated: 2025/11/23 10:02:23 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*ft_get_next_word(const char **s, char c)
{
	size_t	start;
	size_t	len;
	size_t	i;

	i = 0;
	while ((*s)[i] && (*s)[i] == c)
		i++;
	start = i;
	while ((*s)[i] && (*s)[i] != c)
		i++;
	len = i - start;
	*s += i;
	return (ft_substr(*s - i, start, len));
}

char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	size_t	index;
	char	**result;
	char	*current_word;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	index = 0;
	while (index < word_count)
	{
		current_word = ft_get_next_word(&s, c);
		result[index++] = current_word;
		while (*s == c)
			s++;
	}
	result[index] = NULL;
	return (result);
}
