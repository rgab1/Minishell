/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_strings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:04:41 by grivault          #+#    #+#             */
/*   Updated: 2026/03/04 15:22:00 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	free_strings(char **strings)
{
	int	i;

	i = 0;
	if (!strings)
		return ;
	while (strings[i])
		free(strings[i++]);
	free(strings);
}
