/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 19:22:16 by grivault          #+#    #+#             */
/*   Updated: 2025/11/23 09:59:13 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int	ft_strlen_nbr(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] && (s[i] >= 48) && (s[i] <= 57))
		i++;
	return (i);
}

static	int	ft_sign(char c)
{
	if (c == '-')
		return (-1);
	if (c == '+')
		return (1);
	return (0);
}

static int	ft_skip_blanks(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'
		|| s[i] == '\v' || s[i] == '\f' || s[i] == '\r')
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int	unit;
	int	i;
	int	total;
	int	sign;

	nptr += ft_skip_blanks(nptr);
	sign = 1;
	total = 0;
	unit = 1;
	i = ft_strlen_nbr(nptr) - 1;
	if (i < 0 || !nptr)
		return (0);
	while (i >= 0)
	{
		if (!(nptr[i] >= 48 && nptr[i] <= 57))
			sign = ft_sign(nptr[i--]);
		else
		{
			total += (unit * ((nptr[i]) - 48));
			unit *= 10;
			i--;
		}
	}
	return (total * sign);
}
