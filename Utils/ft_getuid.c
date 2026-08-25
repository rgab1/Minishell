/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_UID.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <grivault@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 17:24:33 by grivault          #+#    #+#             */
/*   Updated: 2026/08/25 17:28:12 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <stdio.h>

int	ft_getuid(void)
{
	struct stat	st;

    // Check the stats of standard input (file descriptor 0)
	if (fstat(0, &st) == 0)
        return (st.st_uid); // This is your user ID!
	return (-1); // Error case
}
