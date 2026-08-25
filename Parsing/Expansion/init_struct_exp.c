/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_exp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhalmi <hrhalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 08:52:30 by hassmou           #+#    #+#             */
/*   Updated: 2026/08/25 13:04:28 by hrhalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_exp	*init_exp(void)
{
	t_exp	*exp;

	exp = malloc(sizeof(t_exp));
	if (!exp)
		return (NULL);
	exp->i = 0;
	exp->new_size = 0;
	exp->final_str = NULL;
	exp->in_quot = 0;
	return (exp);
}
