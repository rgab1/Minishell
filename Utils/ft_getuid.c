/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getuid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhalmi <hrhalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 17:24:33 by grivault          #+#    #+#             */
/*   Updated: 2026/09/07 02:18:51 by hrhalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <stdio.h>

int	ft_getuid(void)
{
	struct stat	st;

	if (fstat(0, &st) == 0)
		return (st.st_uid);
	return (-1);
}
