/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 08:25:07 by hrhalmi           #+#    #+#             */
/*   Updated: 2026/05/15 06:23:01 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_tokens    *create_tokens(char *str, t_token_type type)
{
    t_tokens *new;
    
    new = malloc(sizeof(t_tokens));
    if (!new)
        return (NULL);
    new->data = str;
    new->type = type;
    new->next = NULL;
    return (new);    
}

void    ft_lstadd_token(t_tokens **lst, t_tokens *new)
{
    t_tokens    *temp;

    if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
        (*lst)->head = *lst;
		return ;
	}
    temp = *lst;
	while (temp->next != NULL)
        temp = temp->next;
	temp->next = new;
    new->head = *lst;
}

t_tokens    *manage_token(char **tab)
{
    int i;
    t_tokens    *temp;
    t_tokens    *lst;

    lst = NULL;
    i = 0;
    while (tab[i])
    {
        if (ft_strcmp(tab[i], "|") == 0)
            temp = create_tokens(tab[i], PIPE);
        else if (ft_strcmp(tab[i], "<") == 0)
            temp = create_tokens(tab[i], REDIR_IN);
        else if (ft_strcmp(tab[i], ">") == 0)
            temp = create_tokens(tab[i], REDIR_OUT);
        else if (ft_strcmp(tab[i], "<<") == 0)
            temp = create_tokens(tab[i], HREDIR_IN);
        else if (ft_strcmp(tab[i], ">>") == 0)
            temp = create_tokens(tab[i], HREDIR_OUT);
        else
            temp = create_tokens(tab[i], WORD);
        ft_lstadd_token(&lst, temp);
        i++;
    }
    return (lst);
}

void    print_lst(t_tokens  *nodes)
{
    if (nodes == NULL)
        return ;
    while (nodes->next != NULL)
    {
        printf("content = %s; type_nbr = %d\n", nodes->data, nodes->type);
        nodes = nodes->next;
    }
    printf("content = %s; type_nbr = %d\n", nodes->data, nodes->type);
}

int main (int ac, char **av, char **envp)
{
    t_tokens    *nodes;
    char        *line;
    char        **tab;

    nodes = NULL;
    (void) ac;
    (void) av;
    while (1)
    {
        line = readline("My_SHELL> ");
        if (!line)
        {
            printf("exit\n");
            break;
        }
        tab = split_star(line);
        nodes = manage_token(tab);
        
        print_lst(nodes);
    }
    free(line);
    return  (0);
}
