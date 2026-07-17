/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 10:15:34 by hassmou           #+#    #+#             */
/*   Updated: 2026/07/16 18:06:16 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	search_symbols(char const *s, size_t *i, size_t *count)
{
	if (s[(*i)] == '<') 
		search_redir_in(s, i, count);
	else if (s[(*i)] == '>') 
		search_redir_out(s, i, count);
	else if (s[(*i)] == '|')
		search_pipe(s, i, count);
	else
		(*i)++;
}

void	search_redir_in(char const *s, size_t *i, size_t *count)
{
	if (s[(*i) - 1] != ESPACE && s[(*i) - 1] != TAB)
		(*count)++;
	(*i)++;
	if (s[(*i)] && s[(*i)] == '<')
		(*i)++;
	if (s[(*i)] && s[(*i)] != ESPACE && s[(*i)] != TAB)
	{
		printf("alpha after pipe !");
		(*count)++;
	}
}

void	search_redir_out(char const *s, size_t *i, size_t *count)
{
	if (s[(*i) - 1] != ESPACE && s[(*i) - 1] != TAB)
		(*count) += 1;
	(*i)++;
	if (s[(*i)] && s[(*i)] == '>')
		(*i)++;
	if (s[(*i)] && s[(*i)] != ESPACE && s[(*i)] != TAB)
	{
		printf("alpha after pipe !");
		(*count)++;
	}
}

void	search_pipe(char const *s, size_t *i, size_t *count)
{
	if ((s[(*i) - 1] != ESPACE && s[(*i) - 1] != TAB))
		(*count)++;
	(*i)++;
	if (s[(*i)] && s[(*i)] != ESPACE && s[(*i)] != TAB)
	{
		printf("alpha after pipe !");
		(*count)++;
	}
}
