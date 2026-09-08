/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes_from_heredoc.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhalmi <hrhalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 05:28:01 by hrhalmi           #+#    #+#             */
/*   Updated: 2026/09/08 19:06:18 by hrhalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	remove_quotes(char **str)
{
	char	*new_str;

	if (!str || !*str)
		return ;
	new_str = malloc(sizeof(char) * (ft_strlen(*str) + 1));
	if (!new_str)
		return ;
	browse_quotes(new_str, *str);
	free(*str);
	*str = new_str;
}

void	browse_quotes(char *new_str, char *str)
{
	size_t	i;
	size_t	j;
	int		in_sq;
	int		in_dq;

	i = 0;
	j = 0;
	in_sq = 0;
	in_dq = 0;
	while (str[i])
	{
		if (str[i] == '\'' && in_dq == 0)
		{
			in_sq++;
			i++;
		}
		else if (str[i] == '\"' && in_sq == 0)
		{
			in_dq++;
			i++;
		}
		else
			new_str[j++] = str[i++];
	}
	new_str[j] = '\0';
}
