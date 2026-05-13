/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 01:01:22 by hassmou           #+#    #+#             */
/*   Updated: 2026/05/14 00:45:03 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*sub_str;
// 	size_t	s_len;
// 	size_t	actual_len;

// 	if (!s || start < 0)
// 		return (NULL);
// 	s_len = ft_strlen(s);
// 	if (start >= s_len)
// 		return (ft_strdup(""));
// 	actual_len = s_len - start;
// 	if (actual_len > len)
// 		actual_len = len;
// 	sub_str = (char *)malloc(sizeof(char) * (actual_len + 1));
// 	if (sub_str == NULL)
// 		return (NULL);
// 	ft_memcpy(sub_str, s + start, actual_len);
// 	sub_str[actual_len] = '\0';
// 	return (sub_str);
// }

size_t	manage_count_cot(char const *s, size_t *i)
{
	size_t	res;

	res = 0;
	if (s[*i] == SINGLE_COT)
	{
		(*i)++;
		while (s[*i] != SINGLE_COT)
			(*i)++;
		res++;
	}
	else if (s[*i] == DOUBLE_COT)
	{
		(*i)++;
		while (s[*i] != DOUBLE_COT)
			(*i)++;
		res++;
	}
	return (res);
}

static size_t	count_word(char const *s)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		count += manage_count_cot(s, &i);
		if (s[i] != ESPACE && s[i] != TAB)
		{
			count++;
			while (s[i] && (s[i] != ESPACE && s[i] != TAB))
			{
				if (s[i] == SINGLE_COT && s[i] == DOUBLE_COT)
					count += manage_count_cot(s, &i);
				i++;
			}
		}
		else
			i++;
	}
	return (count);
}

size_t	index_in_cot(const char *str, size_t i, int car)
{
	size_t	add;

	add = i;
	if (car == SINGLE_COT)
	{
		i++;
		while (str[i] != SINGLE_COT)
			i++;
		i++;
	}
	else if (car == DOUBLE_COT)
	{
		i++;
		while (str[i] != DOUBLE_COT)
			i++;
		i++;
	}
	add = i - add;
	return (add);
}

static char	*ft_next_word(const char **s)
{
	size_t	start;
	size_t	len;
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

char	**split_star(char const *str)
{
	size_t	word_count;
	size_t	i;
	char	**tab;

	if (!str)
		return (NULL);
	word_count = count_word(str);
	tab = malloc(sizeof(char *) * (word_count + 1));
	if (!tab)
		return (NULL);
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

int	main(void)
{
	const char	*str = " car'Hello' 'World' c'est' Hassan 'eheheh' bye bye";
	char		**tab;
	int			i;

	i = 0;
	tab = split_star(str);
	// while (tab[i] != NULL)
	// {
	// 	printf("%s\n", tab[i]);
	// 	i++;
	// }
    printf("%s\n", tab[2]);
    printf("%s\n", tab[5]);
    printf("%s\n", tab[1]);
	free(tab);
	return (0);
}

/* actuellement sur next word pour recuperer chaque mots.
	l'objectif est de recuperer "..." ou '...'
	par consequent :
	- quand ' trouver chercher jusqu'a ' prochain
	- inversement avec "

	(une autre fonction dedier a cela ?)
	(creer une variable char pour verifier si oui mettre le car dedans jusqu'a
	trouver la meme ?)

*/