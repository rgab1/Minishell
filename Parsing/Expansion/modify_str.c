/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:36:49 by hassmou           #+#    #+#             */
/*   Updated: 2026/07/19 22:51:46 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	modify_expand(const char *str, size_t *i, size_t *new_size,
		t_shell *shell)
{
	size_t	cost_value;

	if (str[(*i) + 1] == '?')
	{
		modify_exit_status(i, new_size, shell);
		return ;
	}
	if (!((ft_isalpha(str[(*i) + 1])) || (str[(*i) + 1] == '_')))
	{
		(*i)++;
		(*new_size)++;
		return ;
	}
	modify_head_value(str, i,new_size, shell);
}

void	modify_head_value(const char *str, size_t *i, size_t *new_size,
		size_t *shell)
{
	char	*key;
	char	*value;
	size_t	start_key;

	(*i)++;
	start_key = (*i);
	while (str[(start_key)] && (ft_isalnum(str[start_key])
			|| (str[start_key] == '_')))
		start_key++;
	key = ft_substr(str, (unsigned int)((*i)), start_key - (*i));
	(*i) = start_key;
	value = get_value(key, shell->env);
	free(key);
}

void	modify_exit_status(size_t *i, size_t *new_size, t_shell *shell)
{
	size_t	cost_value;
	int		tmp;

	cost_value = 0;
	(*i) += 2;
	if (shell->exit_code == 0)
	{
		(*new_size)++;
		return ;
	}
	tmp = shell->exit_code;
	while (tmp >= 10)
	{
		tmp = tmp / 10;
		(*new_size) += 1;
	}
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