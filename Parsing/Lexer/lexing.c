/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 10:15:34 by hassmou           #+#    #+#             */
/*   Updated: 2026/07/15 18:21:40 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	search_symbols(char const *s, size_t *i, size_t *count)
{
	if (s[(*i)] == '<' && (s[(*i) - 1] != ESPACE && s[(*i) - 1] != TAB))
	{
		(*count) += 2;
		(*i)++;
		if (s[(*i)] == '<')
			(*i)++;
	}
	else if (s[(*i)] == '>' && (s[(*i) - 1] != ESPACE && s[(*i) - 1] != TAB))
	{
		(*count) += 2;
		(*i)++;
		if (s[(*i)] == '>')
			(*i)++;
	}
	else if (s[(*i)] == '|' && (s[(*i) - 1] != ESPACE && s[(*i) - 1] != TAB))
	{
		(*count) += 1;
		(*i)++;
	}
	else if (s[(*i)] == SINGLE_COT || s[(*i)] == DOUBLE_COT)
		(*count) += 1;
	else
		(*i)++;
}
	