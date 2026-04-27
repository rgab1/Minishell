/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:02:09 by grivault          #+#    #+#             */
/*   Updated: 2026/04/27 17:53:58 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf_utils.h>
#include <stdlib.h>

int	checks(const char *input, t_printf *data)
{
	if (!input || !data)
	{
		free(data);
		return (1);
	}
	return (0);
}
