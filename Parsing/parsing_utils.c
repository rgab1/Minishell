/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 01:01:22 by hassmou           #+#    #+#             */
/*   Updated: 2026/05/11 01:41:48 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <parsing.h>

size_t  manage_cot(char const *s, size_t *i)
{
    size_t  res;

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

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
        count += manage_cot(s, &i);
		if (s[i] != ESPACE && s[i] != TAB)
		{
			count++;
			while (s[i] && s[i] != ESPACE && s[i] != TAB)
				i++;
		}
		else
			i++;
	}
	return (count);
}

char    **split_star(char const *str, char c)
{
    size_t  word_count;
    size_t  index;

    if (!str)
        return (NULL);
    word_count = count_word()
}