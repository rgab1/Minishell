/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 00:38:16 by hassmou           #+#    #+#             */
/*   Updated: 2026/07/17 21:48:41 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>

size_t	manage_lex(const char **s, size_t start, t_shell *shell)
{
	size_t	i;
	size_t	supp;

	i = start;
	supp = 0;
	while ((*s)[i] && ((*s)[i] != ESPACE && (*s)[i] != TAB))
	{
		if (i == start && (*s)[i] == SINGLE_COT)
			i = index_in_cot(*s, i, &supp, shell);
		else if (i == start && (*s)[i] == DOUBLE_COT)
			i = index_in_cot(*s, i, &supp, shell);
		i++;
	}
	i = i - supp;
	return (i);
}

// POUR INDEX IN WORD
size_t	index_in_cot(const char *str, size_t i, size_t *supp, t_shell *shell)
{
	size_t	value_env;
	size_t	add;

	add = i;
	supp = 0;
	value_env = 0;
	if (str[i] == SINGLE_COT)
	{
		i++;
		while (str[i] != SINGLE_COT)
			i++;
	}
	else if (str[i] == DOUBLE_COT)
	{
		i++;
		while (str[i] != DOUBLE_COT)
		{
			if (str[i] == '$')
				value_env += count_va_env(str, &i, shell, supp);
			else
				i++;
		}
	}
	add = (i - add) + value_env;
	return (add);
}
