/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   things_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 17:49:04 by hassmou           #+#    #+#             */
/*   Updated: 2026/07/07 05:55:33 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// char	*ft_substr_star(char const *s, unsigned int start, size_t len,
// 		t_env *env)
// {
// 	char	*sub_str;
// 	size_t	s_len;
// 	size_t	actual_len;

// 	if (!s)
// 		return (NULL);
// 	s_len = ft_strlen(s);
// 	if (start >= s_len)
// 		return (ft_strdup(""));
// 	actual_len = s_len - start;
// 	if (actual_len > len)
// 		actual_len = len;
// 	sub_str = (char *)malloc(sizeof(char) * (actual_len + 1));
// 	if (sub_str == NULL)
// 		return (NULL);
// 	ft_memcpy(sub_str, s + start, actual_len);
// 	sub_str[actual_len] = '\0';
// 	return (sub_str);
// }

// void	*ft_memcpy_star(void *dest, const void *src, size_t n, t_env *env)
// {
// 	size_t				i;
// 	size_t				j;
// 	unsigned char		*destination;
// 	const unsigned char	*source;


// 	if (!src && !dest)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	destination = (unsigned char *)dest;
// 	source = (const unsigned char *)src;
// 	while (i < n)
// 	{
// 		if (source[i] == '$')
// 		{
// 			if (!change_key_to_value(source, destination, env, i, j))
// 				return (NULL);
// 		}
// 		destination[i] = source[j];
// 		i++;
// 		j++;
// 	}
// 	return (dest);
// }

// int	change_key_to_value(unsigned char *source, unsigned char *destination,
// 		t_env *env, int i, int j)
// {
//     char				*key;
    
// 	key = get_key(*source + (*i), env, i); // regarder 
// 	if (!key)
// 		return (1);
// 	else
// 	{
// 		key = get_value(key, env);
// 		if (key[0] == '\0')
// 			return (1);
// 		(*j) += ft_strlen(key);
// 		while (*key != '\0')
// 		{
// 			destination[(*i)] = *key;
// 			(*i)++;
// 			*key++;
// 		}
// 	}
// 	return (0);
// }
