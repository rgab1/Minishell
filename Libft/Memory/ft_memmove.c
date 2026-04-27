/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 21:47:08 by grivault          #+#    #+#             */
/*   Updated: 2026/04/10 21:11:58 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*source;
	unsigned char		*destination;

	if (dest == NULL || src == NULL)
		return (NULL);
	source = (const unsigned char *)src;
	destination = (unsigned char *)dest;
	if (destination < source)
	{
		i = 0;
		while (i < n)
		{
			destination[i] = source[i];
			i++;
		}
		return (dest);
	}
	i = n;
	while (i > 0)
	{
		--i;
		destination[i] = source[i];
	}
	return (dest);
}
