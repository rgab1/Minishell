/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:42:29 by grivault          #+#    #+#             */
/*   Updated: 2026/04/27 17:54:12 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf_utils.h>
#include <stdlib.h>

t_printf	*data_init(void)
{
	t_printf	*data;

	data = (t_printf *)malloc(sizeof(t_printf));
	if (!data)
		return (NULL);
	data->index = 0;
	data->written_c_count = 0;
	return (data);
}
