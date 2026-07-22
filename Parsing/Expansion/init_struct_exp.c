/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_exp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 08:52:30 by hassmou           #+#    #+#             */
/*   Updated: 2026/07/22 09:00:30 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

t_exp   *init_exp()
{
    t_exp   *exp;
    size_t i;
    size_t  new_size;
    char    *final_str;

    exp = malloc(sizeof(t_exp));
    if (!exp)
        return (NULL);
    exp->i = 0;
    exp->new_size = 0;
    exp->final_str = NULL;
    return (exp);
}