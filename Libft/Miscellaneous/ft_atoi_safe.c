/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:05:19 by grivault          #+#    #+#             */
/*   Updated: 2026/03/04 15:05:20 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_skip_blanks(const char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'
		|| s[i] == '\v' || s[i] == '\f' || s[i] == '\r')
		i++;
	return (i);
}

int	ft_atoi_safe(const char *nptr, int *error)
{
	long	result;
	int		sign;
	int		i;

	if (!nptr || !error)
		return (0);
	i = ft_skip_blanks(nptr);
	result = 0;
	sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			sign = -1;
	if (nptr[i] < '0' || nptr[i] > '9')
		*error = 1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i++] - '0');
		if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
			*error = 1;
	}
	if (nptr[i] != '\0')
		*error = 1;
	return ((int)(result * sign));
}
