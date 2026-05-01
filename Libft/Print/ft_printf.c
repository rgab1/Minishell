/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:23:07 by grivault          #+#    #+#             */
/*   Updated: 2026/05/01 19:20:00 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf_utils.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

static void	conversion_choice(const char *input, t_printf *data, va_list *args)
{
	char	conversion_char;

	conversion_char = input[++data->index];
	data->index++;
	if (conversion_char == 'c')
		ft_putchar_data(va_arg(*args, int), data);
	else if (conversion_char == 's')
		ft_putstr_data(va_arg(*args, char *), data);
	else if (conversion_char == 'd' || conversion_char == 'i')
		ft_putnbr_data(va_arg(*args, int), data);
	else if (conversion_char == '%')
		ft_putpercent_data(data);
	else if (conversion_char == 'u')
		ft_putud_data(va_arg(*args, unsigned int), data);
	else if (conversion_char == 'x')
		ft_putx_data(va_arg(*args, unsigned int), data);
	else if (conversion_char == 'X')
		ft_putxup_data(va_arg(*args, unsigned int), data);
	else if (conversion_char == 'p')
		ft_putptr_data(va_arg(*args, void *), data);
	else
		data->index--;
}

int	ft_printf(const char *input, ...)
{
	int			result;
	t_printf	*data;
	va_list		args;

	data = data_init();
	if (checks(input, data))
		return (-1);
	va_start(args, input);
	while (input[data->index])
	{
		if (input[data->index] == '%')
			conversion_choice(input, data, &args);
		else
		{
			ft_putchar_data(input[data->index], data);
			data->index++;
		}
	}
	va_end(args);
	result = (int)data->written_c_count;
	if (result != (int)data->written_c_count)
		result = -1;
	free(data);
	return (result);
}
