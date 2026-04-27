/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 22:03:01 by grivault          #+#    #+#             */
/*   Updated: 2025/11/22 06:59:11 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	siz_dst;
	size_t	siz_src;
	size_t	i;

	if (!dst || !src)
		return (0);
	siz_dst = ft_strlen(dst);
	siz_src = ft_strlen(src);
	if (siz <= siz_dst)
		return (siz + siz_src);
	i = 0;
	while (src[i] && (siz_dst + i) < (siz - 1))
	{
		dst[siz_dst + i] = src[i];
		i++;
	}
	dst[siz_dst + i] = '\0';
	return (siz_dst + siz_src);
}
