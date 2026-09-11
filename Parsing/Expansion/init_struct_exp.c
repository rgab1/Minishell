/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_exp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhalmi <hrhalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 08:52:30 by hassmou           #+#    #+#             */
/*   Updated: 2026/09/11 19:17:54 by hrhalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_exp	*init_exp(void)
{
	t_exp	*exp;

	exp = malloc(sizeof(t_exp));
	if (!exp)
		return (minishell_error("malloc", ERROR_MALLOC_FAILED_4, NULL), NULL);
	exp->i = 0;
	exp->new_size = 0;
	exp->final_str = NULL;
	exp->in_quot = 0;
	return (exp);
}
