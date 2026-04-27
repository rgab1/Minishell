/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 02:31:05 by grivault          #+#    #+#             */
/*   Updated: 2025/11/22 03:16:08 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*result;
	int		len_s;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	len_s = ft_strlen(s);
	result = (char *)malloc((len_s * sizeof(char)) + 1);
	if (result == NULL)
		return (NULL);
	while (i < len_s)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
