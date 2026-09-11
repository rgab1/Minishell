/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhalmi <hrhalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 13:26:53 by hassmou           #+#    #+#             */
/*   Updated: 2026/09/11 17:55:20 by hrhalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tokens(t_tokens *tokens)
{
	t_tokens	*tmp;

	while (tokens)
	{
		tmp = tokens;
		if (tmp->data != NULL)
			free(tmp->data);
		tokens = tokens->next;
		free(tmp);
	}
	free(tokens);
}

void	free_tokens_error(t_tokens *tokens, t_shell *shell)
{
	t_tokens	*tmp;

	while (tokens)
	{
		tmp = tokens;
		if (tmp->data != NULL)
			free(tmp->data);
		tokens = tokens->next;
		free(tmp);
	}
	free(tokens);
	shell->exit_code = 1;
}
