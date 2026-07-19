/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 00:38:16 by hassmou           #+#    #+#             */
/*   Updated: 2026/07/18 21:55:43 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

size_t	manage_lex(const char **s, size_t start, t_shell *shell)
{
	size_t	i;
	size_t	supp;

	printf("ENTRER DANS MANAGE_LEX\n");
	i = start;
	supp = 0;
	while ((*s)[i] && ((*s)[i] != ESPACE && (*s)[i] != TAB))
	{
		if ((*s)[i] == SINGLE_COT || (*s)[i] == DOUBLE_COT)
			i = index_in_cot(*s, i, &supp, shell);
		else if ((*s)[i] == '$')
			i += count_va_env(*s, &i, &supp, shell);
		else
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
	i++;
	if (str[i] == SINGLE_COT)
	{
		while (str[i] != SINGLE_COT)
			i++;
	}
	else if (str[i] == DOUBLE_COT)
	{
		while (str[i] != DOUBLE_COT)
		{
			if (str[i] == '$')
				value_env += count_va_env(str, &i, supp, shell);
			else
				i++;
		}
	}
	i++;
	add = (i - add) + value_env;
	return (add);
}
