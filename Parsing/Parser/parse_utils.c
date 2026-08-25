/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhalmi <hrhalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 10:41:46 by hassmou           #+#    #+#             */
/*   Updated: 2026/08/25 18:59:25 by hrhalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_tokensize(t_tokens *lst)
{
	int	len;

	len = 0;
	while (lst != NULL && lst->type != PIPE)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

void	add_str(t_tokens **tokens, t_cmd *cmd, int *j_tab)
{
	cmd->cmd[*j_tab] = (*tokens)->data;
	(*tokens)->data = NULL;
	(*j_tab)++;
}
