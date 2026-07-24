/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_for_expand.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 22:29:51 by hassmou           #+#    #+#             */
/*   Updated: 2026/07/23 14:21:48 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	count_expand(char *str, size_t *i, size_t *new_size,
		t_shell *shell)
{
	if (str[(*i) + 1] == '?')
	{
		size_exit_status(i, new_size, shell);
		return ;
	}
	if (!((ft_isalpha(str[(*i) + 1])) || (str[(*i) + 1] == '_')))
	{
		(*i)++;
		(*new_size)++;
		return ;
	}
	(*new_size) += size_head_value(str, i, shell);
}

int	size_head_value(char *str, size_t *i, t_shell *shell)
{
	char	*key;
	size_t	result;
	size_t	start_key;

	(*i)++;
	start_key = (*i);
	while (str[(start_key)] && (ft_isalnum(str[start_key])
			|| (str[start_key] == '_')))
		start_key++;
	key = ft_substr(str, (unsigned int)((*i)), start_key - (*i));
	(*i) = start_key;
	result = ft_strlen(get_value(key, shell->env));
	free(key);
	return (result);
}

void	size_exit_status(size_t *i, size_t *new_size, t_shell *shell)
{
	int		tmp;

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