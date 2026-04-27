/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 03:28:30 by grivault          #+#    #+#             */
/*   Updated: 2026/04/27 17:54:22 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf_utils.h>

void	ft_putnbr_data(int nbr, t_printf *data)
{
	char	*base;
	long	nbrl;

	nbrl = nbr;
	base = "0123456789";
	if (nbrl < 0)
	{
		write(1, "-", 1);
		data->written_c_count++;
		nbrl = -nbrl;
	}
	if (nbrl >= 10)
		ft_putnbr_data(nbrl / 10, data);
	data->written_c_count++;
	write(1, base + (nbrl % 10), 1);
}
