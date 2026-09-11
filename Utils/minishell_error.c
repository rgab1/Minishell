/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhalmi <hrhalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 21:55:07 by grivault          #+#    #+#             */
/*   Updated: 2026/09/11 18:28:11 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	minishell_error(char *context, char *error_msg, char *failed_str)
{
	ft_putstr_fd("minishell: ", 2);
	if (context)
	{
		ft_putstr_fd(context, 2);
		ft_putstr_fd(": ", 2);
	}
	if (failed_str)
	{
		ft_putstr_fd(failed_str, 2);
		ft_putstr_fd(": ", 2);
	}
	if (error_msg)
		ft_putstr_fd(error_msg, 2);
	ft_putstr_fd("\n", 2);
}
