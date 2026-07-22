/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 19:40:31 by hassmou           #+#    #+#             */
/*   Updated: 2026/07/22 09:22:45 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	manage_expand(t_tokens *tokens, t_shell *shell)
{
	t_exp	*exp;

	exp = init_exp();
	get_new_size_exp(exp, tokens, shell);
	exp->final_str = malloc(sizeof(char) * (exp->new_size + 1));
	if (!exp->final_str)
		return (NULL); // gestion d'erreur ici
	exp->new_size = 0;
	exp->i = 0;
	set_newdata_token(exp, tokens, shell);
	exp->final_str[exp->new_size + 1] = '\0';
}

void	set_newdata_token(t_exp *exp, t_tokens *tokens, t_shell *shell)
{
	while (tokens->data[exp->i])
	{
		if (tokens->data[(exp->i)] == SINGLE_COT)
		{
			exp->i++;
			while (tokens->data[exp->i] != SINGLE_COT)
				exp->final_str[exp->new_size++] = tokens->data[exp->i++];
			exp->i++;
		}
		else if (tokens->data[exp->i] == DOUBLE_COT)
			exp->i++;
		else if (tokens->data[exp->i] == '$' && tokens->data[exp->i + 1]
			&& tokens->data[exp->i + 1] == '?')
			modify_exit_status(exp, exp->final_str, shell->exit_code);
		else if (tokens->data[exp->i] == '$')
			modify_expand(tokens->data, exp, shell);
		else
			exp->final_str[exp->new_size++] = tokens->data[exp->i++];
	}
}

void	get_new_size_expand(t_exp *exp, t_tokens *tokens, t_shell *shell)
{
	while (tokens->data[exp->i])
	{
		if (tokens->data[exp->i] == SINGLE_COT)
		{
			exp->i++;
			while (tokens->data[exp->i] != SINGLE_COT)
			{
				exp->i++;
				exp->new_size++;
			}
			exp->i++;
		}
		else if (tokens->data[exp->i] == DOUBLE_COT)
			exp->i++;
		else if (tokens->data[exp->i] == '$')
			count_expand(tokens->data + exp->i, exp->i, exp->new_size, shell);
		else
		{
			exp->i++;
			exp->new_size++;
		}
	}
}
