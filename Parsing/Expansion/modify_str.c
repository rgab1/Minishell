/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhalmi <hrhalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:36:49 by hassmou           #+#    #+#             */
/*   Updated: 2026/08/26 14:49:35 by hrhalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	modify_expand(char *str, t_exp *exp, t_shell *shell)
{
	if (!((ft_isalpha(str[exp->i + 1])) || (str[exp->i + 1] == '_')))
	{
		if (ft_isdigit(str[exp->i + 1]))
			exp->i += 2;
		else if (str[exp->i + 1] == SINGLE_COT)
			exp->i++;
		else if (str[exp->i + 1] == DOUBLE_COT && exp->in_quot == 0)
			exp->i++;
		else
		{
			exp->final_str[exp->new_size] = str[exp->i];
			exp->new_size++;
			exp->i++;
		}
		return ;
	}
	modify_value(str, exp, shell);
}

void	modify_value(char *str, t_exp *exp, t_shell *shell)
{
	char	*key;
	char	*value;
	size_t	start_key;

	exp->i++;
	start_key = exp->i;
	while (str[(start_key)] && (ft_isalnum(str[start_key])
			|| (str[start_key] == '_')))
		start_key++;
	key = ft_substr(str, (unsigned int)(exp->i), start_key - exp->i);
	exp->i = start_key;
	value = get_value(key, shell->env);
	free(key);
	add_expand(value, exp);
}

void	add_expand(char *value, t_exp *exp)
{
	size_t	i;

	i = 0;
	if (!value)
		return ;
	while (value[i])
	{
		exp->final_str[exp->new_size] = value[i];
		i++;
		exp->new_size++;
	}
}

// char	*get_key(unsigned char *src, t_env *env, int *i)
// {
// 	size_t	j;
// 	char	*key;

// 	j = 0;
// 	if ((src[(*i) + 1] >= 65 && src[(*i) + 1] <= 90) || (src[(*i) + 1] >= 97
// 			&& src[(*i) + 1] <= 122) || (src[(*i) + 1] == '_'))
// 		key[j] = src[(*i)];
// 	else
// 		return (NULL);
// 	while (ft_is_env(src[(*i) + 1]))
// 	{
// 		(*i)++;
// 		j++;
// 		key[j] = src[(*i)];
// 	}
// 	if (!ft_is_key(key, env))
// 		return (NULL);
// 	return (key);
// }

// int	ft_is_key(char *key, t_env *head)
// {
// 	size_t	key_len;

// 	*key++;
// 	key_len = ft_strlen(key);
// 	while (head)
// 	{
// 		if (ft_strncmp(key, head->key, key_len + 1))
// 			return (0);
// 		head = head->next;
// 	}
// 	return (1);
// }

// int	ft_is_env(char *str, int first, size_t *i)
// {
// 	if (first == 0 && (!((ft_isalpha(str[(*i) + 1])) && (str[(*i)
// 					+ 1] == '_'))))
// 		return (0);
// 	else if ((ft_isalnum(str[(*i)]) || (str[(*i)] == '_')))
// 		return (0);
// 	else
// 		return (1);
// }

// fonction pour $?