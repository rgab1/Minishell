/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhalmi <hrhalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 15:31:02 by hassmou           #+#    #+#             */
/*   Updated: 2026/08/22 18:17:43 by hrhalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int check_syntax_utils(t_tokens *tmp)
{
	if (tmp->next == NULL || tmp->next->data == NULL)
		return (minishell_error(ERROR_SYNTAXE, "newline"), 1);
	else if (tmp->type == REDIR_IN && tmp->next->type == REDIR_OUT
			&& (tmp->next->next == NULL || tmp->next->next->data == NULL))
		return (minishell_error(ERROR_SYNTAXE, "newline"), 1);
	else if (tmp->next->type != WORD)
		return (minishell_error(ERROR_SYNTAXE, tmp->data), 1);
	return (0);
}

int	check_syntax(t_tokens *tokens)
{
	t_tokens	*tmp;

	tmp = tokens;
	if (tmp && tmp->type == PIPE)
		return (minishell_error(ERROR_SYNTAXE, "|"), 1);
	while (tmp)
	{
		if (tmp->type == REDIR_IN || tmp->type == REDIR_OUT
			|| tmp->type == AREDIR_OUT || tmp->type == HREDIR_IN)
		{
			if (check_syntax_utils(tmp) == 1)
				return (1);
		}
		else if (tmp->type == PIPE)
		{
			if ((tmp->next == NULL || tmp->next->type == PIPE))
				return (minishell_error(ERROR_SYNTAXE, "|"), 1);
		}
		tmp = tmp->next;
	}
	return (0);
}
