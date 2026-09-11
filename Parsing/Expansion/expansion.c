/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhalmi <hrhalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 19:40:31 by hassmou           #+#    #+#             */
/*   Updated: 2026/09/11 18:58:33 by hrhalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	manage_expand(t_tokens *tokens, t_shell *shell)
{
	t_exp	*exp;

	exp = init_exp();
	if (!exp)
		return (-1);
	get_new_size_expand(exp, tokens, shell);
	exp->final_str = malloc(sizeof(char) * (exp->new_size + 1));
	if (!exp->final_str)
		return (minishell_error("malloc", ERROR_MALLOC_FAILED_4, NULL), -1);
	exp->new_size = 0;
	exp->i = 0;
	exp->in_quot = 0;
	set_newdata_token(exp, tokens, shell);
	free(tokens->data);
	tokens->data = exp->final_str;
	free_exp(exp);
	return (0);
}

void	get_new_size_expand(t_exp *exp, t_tokens *tokens, t_shell *shell)
{
	while (tokens->data[exp->i])
	{
		if (tokens->data[exp->i] == SINGLE_COT
			|| tokens->data[exp->i] == DOUBLE_COT)
		{
			tokens->was_quotes++;
			get_new_size_expand_quotes(exp, tokens);
		}
		else if (tokens->data[exp->i] == '$')
			count_expand(tokens->data, &(exp->i), &(exp->new_size), shell);
		else
		{
			exp->i++;
			exp->new_size++;
		}
	}
}

void	get_new_size_expand_quotes(t_exp *exp, t_tokens *tokens)
{
	if (tokens->data[exp->i] == SINGLE_COT)
	{
		if (tokens->data[exp->i] == SINGLE_COT && exp->in_quot == 1)
			exp->new_size++;
		exp->i++;
		if (tokens->data[exp->i] && exp->in_quot == 0)
		{
			while (tokens->data[exp->i] && tokens->data[exp->i] != SINGLE_COT)
			{
				exp->i++;
				exp->new_size++;
			}
			if (tokens->data[exp->i])
				exp->i++;
		}
	}
	else if (tokens->data[exp->i] == DOUBLE_COT)
	{
		if (exp->in_quot == 0)
			exp->in_quot++;
		else
			exp->in_quot--;
		exp->i++;
	}
}

void	set_newdata_token(t_exp *exp, t_tokens *tokens, t_shell *shell)
{
	while (tokens->data[exp->i])
	{
		if (tokens->data[(exp->i)] == SINGLE_COT
			|| tokens->data[exp->i] == DOUBLE_COT)
			set_newdata_quotes(exp, tokens);
		else if (tokens->data[exp->i] == '$' && (tokens->data[exp->i + 1]
				&& tokens->data[exp->i + 1] == '?'))
			modify_exit_status(exp, shell->exit_code);
		else if (tokens->data[exp->i] == '$' && (tokens->data[exp->i + 1]
				&& ft_strncmp(&tokens->data[exp->i + 1], "UID", 3) == 0))
			modify_uid(exp, shell);
		else if (tokens->data[exp->i] == '$')
			modify_expand(tokens->data, exp, shell);
		else
			exp->final_str[exp->new_size++] = tokens->data[exp->i++];
	}
	exp->final_str[exp->new_size] = '\0';
}

void	set_newdata_quotes(t_exp *exp, t_tokens *tokens)
{
	if (tokens->data[(exp->i)] == SINGLE_COT)
	{
		if (tokens->data[exp->i] == SINGLE_COT && exp->in_quot == 1)
			exp->final_str[exp->new_size++] = tokens->data[exp->i];
		exp->i++;
		if (tokens->data[exp->i] && exp->in_quot == 0)
		{
			while (tokens->data[exp->i] && tokens->data[exp->i] != SINGLE_COT)
				exp->final_str[exp->new_size++] = tokens->data[exp->i++];
			if (tokens->data[exp->i])
				exp->i++;
		}
	}
	else if (tokens->data[exp->i] == DOUBLE_COT)
	{
		if (exp->in_quot == 0)
			exp->in_quot++;
		else
			exp->in_quot--;
		exp->i++;
	}
}
