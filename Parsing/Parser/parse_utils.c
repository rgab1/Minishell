/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 10:41:46 by hassmou           #+#    #+#             */
/*   Updated: 2026/07/15 17:18:43 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
	(*j_tab)++;
}

// void    add_str(t_tokens **tokens, t_cmd *cmd, int *j_tab)
// {
//     dprintf(2, "[TRACE] add_str : Ajout du mot '%s' à l'index %d\n", (*tokens)->data, *j_tab);
//     cmd->cmd[*j_tab] = (*tokens)->data;
//     (*j_tab)++;
// }

void	put_cmd(t_cmd *cmd)
{
	int	i;
	int	j;

	if (!cmd)
		printf("NOOOO\n");
	i = 0;
	j = 0;
	while (cmd)
	{
		printf("ENTRER DANS BOUCLE\n");
		while (cmd->cmd[j])	
			{
				printf("cmd : %d - %s\n", i, cmd->cmd[j]);\
				j++;
			}
		printf("cmd : %d - %d\n", i, cmd->in_fd);
		printf("cmd : %d - %d\n", i, cmd->out_fd);
		printf("----------------------\n");
		cmd = cmd->next;
		i++;
		j = 0;
	}
}

/* Il faut encore gerer la suppression de memoire et parser le fait que le debut soit un WORD */