/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 01:01:22 by hassmou           #+#    #+#             */
/*   Updated: 2026/07/15 19:46:18 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// POUR COUNT WORD ET MALLOC (i++ pour les " a ignorer)
int	manage_count_cot(const char *s, size_t *i)
{
	if (s[*i] == SINGLE_COT)
	{
		(*i)++;
		while (s[*i] != SINGLE_COT)
		{
			if (s[*i] == '\0')
				return (1);
			(*i)++;
		}
	}
	else if (s[*i] == DOUBLE_COT)
	{
		(*i)++;
		while (s[*i] != DOUBLE_COT)
		{
			if (s[*i] == '\0')
				return (1);
			(*i)++;
		}
	}
	return (0);
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
			break;
		count++;
		while (s[i] && (s[i] != ESPACE && s[i] != TAB))
		{
			if (s[i] == SINGLE_COT || s[i] == DOUBLE_COT)
			{
				if (manage_count_cot(s, &i) == 1)
					return (0);// WIP Return minishell_error (print)
			}
			if (s[i])
				search_symbols(s, &i, &count);
		}
	}
	printf("words = %d\n", count);
	return (count);
}

char	*ft_next_word(const char **s, t_env *env)
{
	size_t	start;
	size_t	len;
	size_t	i;
	char	*word;

	i = 0;
	while ((*s)[i] && ((*s)[i] == ESPACE || (*s)[i] == TAB))
		i++;
	start = i;
	i = manage_lex(s, start, env);
	*s += i;
	word = ft_substr(*s - i, start, i - start);
	return (word);
}
// Il faut changer le $USER en Hassmou dans la string

char	**split_star(char const *str, t_env *env)
{
	size_t	word_count;
	size_t	i;
	char	**tab;

	if (!str)
		return (NULL);
	word_count = count_word(str);
	if (word_count == 0)
		return (NULL);
	tab = malloc(sizeof(char *) * (word_count + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		tab[i] = ft_next_word(&str, env);
		i++;
		while (*str == ESPACE || *str == TAB)
			str++;
	}
	tab[i] = NULL;
	return (tab);
}

// int	main(void)
// {
// 	const char	*str = " car'Hello' < << > >> | 'World' c'est' Hassan 'eheheh' bye bye";
// 	char		**tab;
// 	int			i;

// 	i = 0;
// 	tab = split_star(str);
// 	// while (tab[i] != NULL)
// 	// {
// 	// 	printf("%s\n", tab[i]);
// 	// 	i++;
// 	// }
//     printf("%s\n", tab[2]);
//     printf("%s\n", tab[5]);
//     printf("%s\n", tab[1]);
// 	free(tab);
// 	return (0);
// }
