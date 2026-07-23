/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 08:25:07 by hrhalmi           #+#    #+#             */
/*   Updated: 2026/07/23 07:43:24 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	free_tab(char **tab)
{
	size_t i;

	i = 0;
	while (tab[i])
	{
		i++;
		free(tab[i - 1]);
	}
	free(tab);
}

t_tokens	*create_tokens(char *str, t_token_type type)
{
	t_tokens	*new;

	new = malloc(sizeof(t_tokens));
	if (!new)
		return (NULL);
	new->data = str;
	new->type = type;
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

t_tokens	*manage_token(char **tab, t_shell *shell)
{
	int			i;
	t_tokens	*temp;
	t_tokens	*lst;

	lst = NULL;
	i = 0;
	while (tab[i])
	{
		if (ft_strcmp(tab[i], "|") == 0)
			temp = create_tokens(tab[i], PIPE);
		else if (ft_strncmp(tab[i], "<<", 2) == 0)
			temp = create_tokens(tab[i], HREDIR_IN);
		else if (ft_strncmp(tab[i], ">>", 2) == 0)
			temp = create_tokens(tab[i], AREDIR_OUT);
		else if (ft_strncmp(tab[i], "<", 1) == 0)
			temp = create_tokens(tab[i], REDIR_IN);
		else if (ft_strncmp(tab[i], ">", 1) == 0)
			temp = create_tokens(tab[i], REDIR_OUT);
		else
			temp = create_tokens(tab[i], WORD);
		ft_lstadd_token(&lst, temp);
		i++;
	}
	expand_tokens(lst, shell);
	return (lst);
}

void	expand_tokens(t_tokens *tokens, t_shell *shell)
{
	t_tokens *tmp;

	tmp = tokens;
	while (tmp)
	{
		manage_expand(tmp, shell);
		tmp = tmp->next;
	}
}

/* il faut creer une boucle (jusqu'a que la liste soit vide ou qu'il y a un pipe)
et inserer la data dans la struct :

typedef struct s_cmd
{
	char            **argv;      // Le tableau de la commande (ex: ["grep",
		"hassan", NULL])
	char            *infile;   
		// Si une redirection < est présente dans CE bloc
	char            *outfile;  
		// Si une redirection > ou >> est présente dans CE bloc
	int             redir_type; // Pour savoir si c'est >, >>, etc.
	struct s_cmd    *next;     
		// Pointeur vers la commande SUIVANTE (après le pipe)
}			t_cmd;
*/
