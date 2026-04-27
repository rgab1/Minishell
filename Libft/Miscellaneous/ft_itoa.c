/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 04:26:57 by grivault          #+#    #+#             */
/*   Updated: 2025/11/23 09:59:59 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*int_max_min_handler(int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 2147483647)
		return (ft_strdup("2147483647"));
	return (NULL);
}

static size_t	ft_intlen(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*result;
	size_t	sign;
	size_t	int_len;

	result = int_max_min_handler(n);
	if (result)
		return (result);
	sign = (n < 0);
	if (sign)
		n *= -1;
	int_len = ft_intlen(n);
	result = (char *)malloc(sizeof(char) * (int_len + 1 + sign));
	if (!result)
		return (NULL);
	result[int_len + sign] = '\0';
	while (int_len--)
	{
		result[int_len + sign] = (n % 10) + 48;
		n /= 10;
	}
	if (sign)
		result[0] = '-';
	return (result);
}
