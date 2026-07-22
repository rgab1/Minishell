/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:36:49 by hassmou           #+#    #+#             */
/*   Updated: 2026/07/22 09:30:20 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	modify_expand(const char *str, t_exp *exp, t_shell *shell)
{
	if (!((ft_isalpha(str[exp->i + 1])) || (str[exp->i + 1] == '_')))
	{
		exp->final_str[exp->new_size] = str[exp->i];
		exp->i++;
		exp->new_size++;
		return ;
	}
	modify_head_value(str, exp, shell);
}

void	modify_head_value(const char *str, t_exp *exp, size_t *shell)
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
}

void	modify_exit_status(t_exp *exp, char *final_str, int exit_code)
{
	exp->i += 2;
	if (exit_code == 0)
	{
		exp->final_str[exp->new_size] = '0';
		exp->new_size++;
		return ;
	}
	recursive_exit_status(&exp->new_size, final_str, exit_code);
}

void	recursive_exit_status(size_t *new_size, char *final_str, int exit_code)
{
	if (exit_code >= 10)
		recursive_exit_status(new_size, final_str, exit_code / 10);
	final_str[(*new_size)] = (exit_code % 10) + '0';
	(*new_size) += 1;
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