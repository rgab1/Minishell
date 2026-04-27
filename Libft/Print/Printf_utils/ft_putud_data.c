/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putud_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 03:28:30 by grivault          #+#    #+#             */
/*   Updated: 2026/04/27 17:54:31 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf_utils.h>

void	ft_putud_data(unsigned int ud, t_printf *data)
{
	char	*base;

	base = "0123456789";
	if (ud >= 10)
		ft_putud_data(ud / 10, data);
	data->written_c_count++;
	write(1, base + (ud % 10), 1);
}
