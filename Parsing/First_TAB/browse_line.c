/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 00:38:16 by hassmou           #+#    #+#             */
/*   Updated: 2026/05/15 04:47:32 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>

size_t	manage_lex(const char **s, size_t start)
{
	size_t	i;

	i = start;
	while ((*s)[i] && ((*s)[i] != ESPACE && (*s)[i] != TAB))
	{
		if (i == start && (*s)[i] == SINGLE_COT)
		{
			i += index_in_cot(*s, i, SINGLE_COT);
			break ;
		}
		else if (i == start && (*s)[i] == DOUBLE_COT)
		{
			i += index_in_cot(*s, i, DOUBLE_COT);
			break ;
		}
		else if (i != start && ((*s)[i] == SINGLE_COT || (*s)[i] == DOUBLE_COT))
			break ;
		i++;
	}
	return (i);
}

// POUR INDEX IN WORD
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