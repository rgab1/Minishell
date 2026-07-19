/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 19:40:31 by hassmou           #+#    #+#             */
/*   Updated: 2026/07/19 21:53:44 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	manage_expand(t_tokens *tokens, t_shell *shell)
{
	size_t	i;
	size_t	new_size;
    char    *final_str;

	i = 0;
	new_size = 0;
    get_new_size_exp(&i, &new_size, tokens, shell);
    final_str = malloc(sizeof(char) * (new_size + 1));
    if (!final_str)
        return (NULL); // gestion d'erreur ici
    final_str[new_size + 1] = '\0';
    
}

char    *set_data_token(size_t *new_size, )
{
    
}

void	get_new_size_expand(size_t *i, size_t *new_size, t_tokens *tokens,
		t_shell *shell)
{
	while (tokens->data[(*i)])
	{
		if (tokens->data[(*i)] == SINGLE_COT)
		{
			(*i)++;
			while (tokens->data[(*i)] != SINGLE_COT)
			{
				(*i)++;
				(*new_size)++;
			}
			(*i)++;
		}
		if (tokens->data[(*i)] == DOUBLE_COT)
			(*i)++;
		if (tokens->data[(*i)] == '$')
			count_expand(tokens->data + (*i), i, new_size, shell);
		(*i)++;
		(*new_size)++;
	}
}
