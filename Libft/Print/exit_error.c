/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 21:00:04 by grivault          #+#    #+#             */
/*   Updated: 2026/04/10 21:00:06 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	exit_error(char *error_msg, int error_code)
{
	puterror(error_msg);
	exit(error_code);
}
