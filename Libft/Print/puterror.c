/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puterror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 20:59:51 by grivault          #+#    #+#             */
/*   Updated: 2026/04/10 20:59:53 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	puterror(char *error_msg)
{
	if (!error_msg)
		return ;
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error_msg, 2);
}
