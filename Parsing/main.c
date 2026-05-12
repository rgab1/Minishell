/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 08:25:07 by hrhalmi           #+#    #+#             */
/*   Updated: 2026/05/12 06:07:27 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_tokens    *create_tokens(int i, char *str, t_token_type type, 
                t_tokens *head)
{
    t_tokens *new;
    
    new = malloc(sizeof(t_tokens));
    if (!new)
        return (NULL);
    new->data = str;
    new->type = type;
    new->next = NULL;
    if (i == 1)
        head = new;
    new->head = head;
    return (new);    
}

void    lexer(char *tab, t_tokens *nodes, t_tokens *head)
{
    int i;
    
    i = 1;
    while (tab[i])
    {
        if (tab[i] == "|")
            nodes = create_tokens(i, tab[i], PIPE, head);
        else if (tab[i] == "<")
            nodes = create_tokens(i, tab[i], REDIR_IN, head);
        else if (tab[i] == ">")
            nodes = create_tokens(i, tab[i], REDIR_OUT, head);
        else if (tab[i] == "<<")
            nodes = create_tokens(i, tab[i], HREDIR_IN, head);
        else if (tab[i] == ">>")
            nodes = create_tokens(i, tab[i], HREDIR_OUT, head);
        else
            nodes = create_tokens(i, tab[i], WORD, head);
        nodes = nodes->next;
        i++;
    }
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
    t_tokens    *head;
    char        *line;

    nodes = NULL;
    head = NULL;
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
        lexer(line, nodes, head);
        print_lst(nodes);
    }
    free(line);
    return  (0);
}
