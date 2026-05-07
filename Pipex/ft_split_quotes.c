/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 04:46:43 by grivault          #+#    #+#             */
/*   Updated: 2026/03/25 06:14:33 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;
	char	quote;

	count = 0;
	i = 0;
	quote = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && (s[i] != c || quote))
		{
			if (s[i] == '\\' && s[i + 1])
				i++;
			else if (!quote && (s[i] == '\'' || s[i] == '"'))
				quote = s[i];
			else if (quote && s[i] == quote)
				quote = 0;
			i++;
		}
	}
	return (count);
}

static size_t	get_word_len(const char *s, char c)
{
	size_t	len;
	char	q;

	len = 0;
	q = 0;
	while (*s && (*s != c || q))
	{
		if (*s == '\\' && *(s + 1))
		{
			s++;
			len++;
		}
		else if (!q && (*s == '\'' || *s == '"'))
			q = *s;
		else if (q && *s == q)
			q = 0;
		else
			len++;
		s++;
	}
	return (len);
}

static void	copy_word(char *w, const char **s, char c)
{
	size_t	i;
	char	q;

	i = 0;
	q = 0;
	while (**s && (**s != c || q))
	{
		if (**s == '\\' && *(*s + 1))
			w[i++] = *(++(*s));
		else if (!q && (**s == '\'' || **s == '"'))
			q = **s;
		else if (q && **s == q)
			q = 0;
		else
			w[i++] = **s;
		(*s)++;
	}
	w[i] = '\0';
}

static char	*ft_get_next_word(const char **s, char c)
{
	char	*w;

	while (**s && **s == c)
		(*s)++;
	w = malloc(sizeof(char) * (get_word_len(*s, c) + 1));
	if (!w)
		return (NULL);
	copy_word(w, s, c);
	return (w);
}

char	**ft_split_quotes(char const *s, char c)
{
	size_t	word_count;
	size_t	i;
	char	**result;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < word_count)
		result[i++] = ft_get_next_word(&s, c);
	result[i] = NULL;
	return (result);
}
