/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhalmi <hrhalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 10:15:34 by hassmou           #+#    #+#             */
/*   Updated: 2026/08/22 22:05:36 by hrhalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	if ((*i) != 0 && s[(*i) - 1] != ESPACE && s[(*i) - 1] != TAB)
		(*count)++;
	(*i)++;
	if (s[(*i)] && s[(*i)] == '<')
		(*i)++;
	if (s[(*i)] && s[(*i)] != ESPACE && s[(*i)] != TAB
		&& s[(*i)] != '|' && s[(*i)] != '>')
		(*count)++;
}

void	search_redir_out(char const *s, size_t *i, size_t *count)
{
	if ((*i) != 0 && s[(*i) - 1] != ESPACE && s[(*i) - 1] != TAB)
		(*count)++;
	(*i)++;
	if (s[(*i)] && s[(*i)] == '>')
		(*i)++;
	if (s[(*i)] && s[(*i)] != ESPACE && s[(*i)] != TAB
		&& s[(*i)] != '|' && s[(*i)] != '<')
		(*count)++;
}

void	search_pipe(char const *s, size_t *i, size_t *count)
{
	if (((*i) != 0 && s[(*i) - 1] != ESPACE && s[(*i) - 1] != TAB)
		 && s[(*i) - 1] != '|')
		(*count)++;
	(*i)++;
	if (s[(*i)] && s[(*i)] != ESPACE && s[(*i)] != TAB)
		(*count)++;
}
