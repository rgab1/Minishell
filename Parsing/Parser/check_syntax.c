/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhalmi <hrhalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 15:31:02 by hassmou           #+#    #+#             */
/*   Updated: 2026/08/22 07:49:40 by hrhalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_syntax(t_tokens *tokens)
{
	t_tokens	*tmp;
	int			i;

	i = 0;
	tmp = tokens;
	if (tmp && tmp->type == PIPE)
		return (minishell_error(ERROR_SYNTAXE, "|"), 1);
	while (tmp)
	{
		if (tmp->type == REDIR_IN || tmp->type == REDIR_OUT
			|| tmp->type == AREDIR_OUT || tmp->type == HREDIR_IN)
		{
			if (tmp->next == NULL || tmp->next->data == NULL
				|| tmp->next->type != WORD)
				return (minishell_error(ERROR_SYNTAXE, tmp->data), 1);
		}
		else if (tmp->type == PIPE)
		{
			if ((tmp->next == NULL || tmp->next->type == PIPE) || i == 0)
				return (minishell_error(ERROR_SYNTAXE, "|"), 1);
		}
		tmp = tmp->next;
		i++;
	}
	return (0);
}
