/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 19:40:31 by hassmou           #+#    #+#             */
/*   Updated: 2026/07/23 07:45:09 by hassmou          ###   ########.fr       */
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
		return ; // gestion d'erreur ici
	exp->new_size = 0;
	exp->i = 0;
	set_newdata_token(exp, tokens, shell);
	exp->final_str[exp->new_size] = '\0';
	free(tokens->data);
	tokens->data = ft_strdup(exp->final_str);
	free_exp(exp);
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
			count_expand(tokens->data, &(exp->i), &(exp->new_size),
				shell);
		else
		{
			exp->i++;
			exp->new_size++;
		}
	}
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
			modify_exit_status(exp, shell->exit_code);
		else if (tokens->data[exp->i] == '$')
			modify_expand(tokens->data, exp, shell);
		else
			exp->final_str[exp->new_size++] = tokens->data[exp->i++];
	}
}

void	free_exp(t_exp *exp)
{
	if (exp->final_str)
		free(exp->final_str);
	free(exp);
}