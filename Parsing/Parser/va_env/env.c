/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:36:49 by hassmou           #+#    #+#             */
/*   Updated: 2026/07/01 18:55:23 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	count_va_env(const char *str, size_t *i, t_env *env)
{
    size_t j;
    char    *compare;
    
	if (!((str[(*i) + 1] >= 65 && str[(*i) + 1] <= 90) 
            || (str[(*i) + 1] >= 97 && str[(*i) + 1] <= 122)
                || (str[(*i) + 1] != '_')))
        return ;
    (*i)++;
    j = (*i);
    while (((str[(*i)] >= 48 && str[(*i)] <= 57)
            || (str[(*i)] >= 65 && str[(*i)] <= 90) 
                || (str[(*i)] >= 97 && str[(*i)] <= 122)
                    || (str[(*i)] == '_')))
        {
            (*i)++;
            j++;
        }
    compare = ft_substr(str, (unsigned int) (*i), j - (*i));
    printf("%d, %s", (*i), compare);
    (*i) += ft_strlen(get_value(compare, env));
    printf("%d, %s", (*i), compare);
}
