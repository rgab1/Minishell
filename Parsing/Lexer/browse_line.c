/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 00:38:16 by hassmou           #+#    #+#             */
/*   Updated: 2026/07/07 09:27:47 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>

size_t	manage_lex(const char **s, size_t start, t_env *env)
{
	size_t	i;

	i = start;
	while ((*s)[i] && ((*s)[i] != ESPACE && (*s)[i] != TAB))
	{
		if (i == start && (*s)[i] == SINGLE_COT)
		{
			i = index_in_cot(*s, i, SINGLE_COT, env);
		}
		else if (i == start && (*s)[i] == DOUBLE_COT)
		{
			i = index_in_cot(*s, i, DOUBLE_COT, env);
		}
		i++;
	}
	return (i);
}

// POUR INDEX IN WORD
size_t	index_in_cot(const char *str, size_t i, int car, t_env *env)
{
	size_t	value_env;
	size_t	add;
	size_t	supp;

	add = i;
	supp = 0;
	value_env = 0;
	if (car == SINGLE_COT)
	{
		i++;
		while (str[i] != SINGLE_COT)
			i++;
	}
	else if (car == DOUBLE_COT)
	{
		i++;
		while (str[i] != DOUBLE_COT)
		{
			if (str[i] == '$')
				value_env += count_va_env(str, &i, env, &supp);
			else
				i++;
		}
	}
	add = (i - add) + value_env - supp;
	return (add);
}
