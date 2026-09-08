/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhalmi <hrhalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 15:31:02 by hassmou           #+#    #+#             */
/*   Updated: 2026/09/08 19:07:17 by hrhalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_max_heredc(t_tokens *tokens)
{
	int			i_heredc;
	t_tokens	*tmp;

	i_heredc = 0;
	tmp = tokens;
	while (tmp)
	{
		if (i_heredc >= 17)
			return (minishell_error(ERROR_MAX_HEREDOC, NULL), 1);
		if (tmp->type == HREDIR_IN)
			i_heredc++;
		tmp = tmp->next;
	}
	return (0);
}

static int	check_syntax_redir(t_tokens *tmp)
{
	if (tmp->next == NULL || tmp->next->data == NULL)
		return (minishell_error(ERROR_SYNTAXE, "newline"), 1);
	else if (tmp->type == REDIR_IN && tmp->next->type == REDIR_OUT
		&& (tmp->next->next == NULL || tmp->next->next->data == NULL))
		return (minishell_error(ERROR_SYNTAXE, "newline"), 1);
	else if (tmp->next != NULL && tmp->next->type != WORD)
		return (minishell_error(ERROR_SYNTAXE, tmp->next->data), 1);
	else if (tmp->type == HREDIR_IN
		&& (tmp->next->next && tmp->next->next->type == HREDIR_IN))
	{
		if (check_max_heredc(tmp) == 1)
			return (1);
	}
	return (0);
}

static int	check_syntaxe_pipe(t_tokens *tmp)
{
	if (tmp->next == NULL)
		return (minishell_error(ERROR_SYNTAXE, "|"), 1);
	else if (tmp->next->type == PIPE)
		return (minishell_error(ERROR_SYNTAXE, tmp->next->data), 1);
	return (0);
}

void	clear_impostor_tokens(t_tokens **current)
{
	t_tokens	*tmp;
	t_tokens	*prev;
	t_tokens	*next_nodes;

	next_nodes = NULL;
	tmp = (*current);
	prev = NULL;
	while (tmp)
	{
		if (tmp->data && tmp->data[0] == '\0' && tmp->was_quotes == 0)
		{
			next_nodes = tmp->next;
			if (prev)
				prev->next = next_nodes;
			else
				(*current) = next_nodes;
			free(tmp->data);
			free(tmp);
			tmp = next_nodes;
			continue ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
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
			if (check_syntax_redir(tmp) == 1)
				return (1);
		}
		else if (tmp->type == PIPE)
		{
			if (check_syntaxe_pipe(tmp) == 1)
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
