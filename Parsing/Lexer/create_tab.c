/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhalmi <hrhalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 01:01:22 by hassmou           #+#    #+#             */
/*   Updated: 2026/08/22 22:04:55 by hrhalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	index_count_cot(const char *str, size_t *i)
{
	if (str[*i] == SINGLE_COT)
	{
		(*i)++;
		while (str[*i] != SINGLE_COT)
			(*i)++;
	}
	else if (str[*i] == DOUBLE_COT)
	{
		(*i)++;
		while (str[*i] != DOUBLE_COT)
			(*i)++;
	}
	(*i)++;
}

size_t	manage_lex(const char **s, size_t start)
{
	size_t	i;

	i = start;
	if ((*s)[i] == '<' || (*s)[i] == '>' || (*s)[i] == '|')
	{
		i++;
		if (((*s)[i - 1] == '<' && (*s)[i] && (*s)[i] == '<')
			|| ((*s)[i - 1] == '>' && (*s)[i] && (*s)[i] == '>'))
			i++;
		return (i);
	}
	while ((*s)[i] && ((*s)[i] != ESPACE && (*s)[i] != TAB) && ((*s)[i] != '<'
			&& (*s)[i] != '>' && (*s)[i] != '|'))
	{
		if ((*s)[i] == SINGLE_COT || (*s)[i] == DOUBLE_COT)
			index_count_cot(*s, &i);
		else
			i++;
	}
	return (i);
}

size_t	count_word(char const *s)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == ESPACE || s[i] == TAB))
			i++;
		if (!s[i])
			break ;
		count++;
		while (s[i] && (s[i] != ESPACE && s[i] != TAB))
		{
			if (s[i] == SINGLE_COT || s[i] == DOUBLE_COT)
				index_count_cot(s, &i);
			else if (s[i])
				search_symbols(s, &i, &count);
		}
	}
	return (count);
}

char	*ft_next_word(const char **s)
{
	size_t	start;
	size_t	i;
	char	*word;

	i = 0;
	while ((*s)[i] && ((*s)[i] == ESPACE || (*s)[i] == TAB))
		i++;
	start = i;
	i = manage_lex(s, start);
	*s += i;
	word = ft_substr(*s - i, start, i - start);
	return (word);
}
// Il faut changer le $USER en Hassmou dans la string

char	**split_star(char const *str)
{
	size_t	word_count;
	size_t	i;
	char	**tab;

	if (!str)
		return (NULL);
	word_count = count_word(str);
	printf("%ld\n", word_count);
	if (word_count == 0)
		return (NULL);
	tab = malloc(sizeof(char *) * (word_count + 1));
	if (!tab)
		return (minishell_error("Malloc ", ERROR_MALLOC_FAILED_4), NULL);
	i = 0;
	while (i < word_count)
	{
		tab[i] = ft_next_word(&str);
		i++;
		while (*str == ESPACE || *str == TAB)
			str++;
	}
	tab[i] = NULL;
	return (tab);
}
