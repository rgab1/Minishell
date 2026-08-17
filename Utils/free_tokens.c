/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 13:26:53 by hassmou           #+#    #+#             */
/*   Updated: 2026/08/06 17:17:13 by hassmou          ###   ########.fr       */
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
