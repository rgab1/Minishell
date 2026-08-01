/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 15:31:02 by hassmou           #+#    #+#             */
/*   Updated: 2026/08/01 06:08:49 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int check_syntax(t_tokens *tokens)
{
    t_tokens *tmp;
    
    tmp = tokens;
    if (tmp && tmp->type == PIPE)
        return (minishell_error(ERROR_SYNTAXE, "|"), 1);
    while (tmp)
    {
        if (tmp->type == REDIR_IN || tmp->type == REDIR_OUT 
            || tmp->type == AREDIR_OUT || tmp->type == HREDIR_IN)
        {
            if (tmp->next == NULL || tmp->next->data == NULL
                    || tmp->next->type != WORD)
                return (minishell_error(ERROR_SYNTAXE, tmp->data),1);
        }
        else if (tmp->type == PIPE)
        {
            if (tmp->next == NULL || tmp->next->type == PIPE)
                return (minishell_error(ERROR_SYNTAXE, "|"),1);
        }
        tmp = tmp->next;
    }
    return (0);
}
