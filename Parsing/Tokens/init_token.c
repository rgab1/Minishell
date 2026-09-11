/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhalmi <hrhalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 08:25:07 by hrhalmi           #+#    #+#             */
/*   Updated: 2026/09/11 17:55:46 by hrhalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tokens	*create_tokens(char *str, t_token_type type)
{
	t_tokens	*new;

	new = malloc(sizeof(t_tokens));
	if (!new)
		return (NULL);
	new->data = str;
	new->type = type;
	new->was_quotes = 0;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_token(t_tokens **lst, t_tokens *new)
{
	t_tokens	*temp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

t_tokens	*compare_for_create_token(char **tab, int i)
{
	if (ft_strcmp(tab[i], "|") == 0)
		return (create_tokens(tab[i], PIPE));
	else if (ft_strncmp(tab[i], "<<", 2) == 0)
		return (create_tokens(tab[i], HREDIR_IN));
	else if (ft_strncmp(tab[i], ">>", 2) == 0)
		return (create_tokens(tab[i], AREDIR_OUT));
	else if (ft_strncmp(tab[i], "<", 1) == 0)
		return (create_tokens(tab[i], REDIR_IN));
	else if (ft_strncmp(tab[i], ">", 1) == 0)
		return (create_tokens(tab[i], REDIR_OUT));
	else
		return (create_tokens(tab[i], WORD));
}

t_tokens	*manage_token(char **tab, t_shell *shell)
{
	int			i;
	t_tokens	*temp;
	t_tokens	*lst;

	lst = NULL;
	temp = NULL;
	i = 0;
	while (tab[i])
	{
		temp = compare_for_create_token(tab, i);
		ft_lstadd_token(&lst, temp);
		i++;
	}
	if (expand_tokens(lst, shell))
		return (NULL);
	return (lst);
}

int	expand_tokens(t_tokens *tokens, t_shell *shell)
{
	t_tokens	*tmp;

	tmp = tokens;
	while (tmp)
	{
		if (tmp->type == HREDIR_IN)
		{
			if (tmp->next && tmp->next->type == WORD)
			{
				tmp = tmp->next;
				if (ft_strchr(tmp->data, SINGLE_COT)
					|| ft_strchr(tmp->data, DOUBLE_COT))
					tmp->was_quotes = 1;
				remove_quotes(&tmp->data);
			}
		}
		else
		{
			if (manage_expand(tmp, shell) == -1)
				return (free_tokens_error(tokens, shell), -1);
		}
		tmp = tmp->next;
	}
	return (0);
}
