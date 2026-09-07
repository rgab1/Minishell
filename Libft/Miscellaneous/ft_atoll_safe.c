/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll_safe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 21:23:03 by grivault          #+#    #+#             */
/*   Updated: 2026/09/07 22:22:22 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

long long	ft_atoll_safe(const char *str, int *error)
{
	unsigned long long	result;
	int					sign;
	int					i;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	if (!str[i])
	{
		*error = 1;
		return (0);
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			*error = 1;
			return (0);
		}
		result = result * 10 + (str[i++] - '0');
		if (result > 9223372036854775807ULL + (sign == -1))
		{
			*error = 1;
			return (0);
		}
	}
	return ((long long)(result * sign));
}
