/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_exit_status.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhalmi <hrhalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 14:49:08 by hrhalmi           #+#    #+#             */
/*   Updated: 2026/08/26 14:49:24 by hrhalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	modify_exit_status(t_exp *exp, int exit_code)
{
	exp->i += 2;
	if (exit_code == 0)
	{
		exp->final_str[exp->new_size] = '0';
		exp->new_size++;
		return ;
	}
	recursive_exit_status(&(exp->new_size), exp->final_str, exit_code);
}

void	recursive_exit_status(size_t *new_size, char *final_str, int exit_code)
{
	if (exit_code >= 10)
		recursive_exit_status(new_size, final_str, exit_code / 10);
	final_str[(*new_size)] = (exit_code % 10) + '0';
	(*new_size) += 1;
}
