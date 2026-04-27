/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxup_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 12:10:17 by grivault          #+#    #+#             */
/*   Updated: 2026/04/27 17:54:32 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf_utils.h>

void	ft_putxup_data(unsigned int X, t_printf *data)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (X >= 16)
		ft_putxup_data(X / 16, data);
	data->written_c_count++;
	write(1, base + (X % 16), 1);
}
