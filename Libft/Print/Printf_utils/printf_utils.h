/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 23:22:49 by grivault          #+#    #+#             */
/*   Updated: 2026/04/27 17:55:10 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_UTILS_H
# define PRINTF_UTILS_H
# include <unistd.h>
# include <libft.h>

typedef struct s_printf
{
	size_t	index;
	size_t	written_c_count;
}				t_printf;

t_printf	*data_init(void);
int			checks(const char *input, t_printf *data);
void		ft_putchar_data(int c, t_printf *data);
void		ft_putstr_data(char *str, t_printf *data);
void		ft_putptr_data(void *ptr, t_printf *data);
void		ft_putnbr_data(int nbr, t_printf *data);
void		ft_putud_data(unsigned int ud, t_printf *data);
void		ft_putx_data(unsigned int x, t_printf *data);
void		ft_putxup_data(unsigned int X, t_printf *data);
void		ft_putpercent_data(t_printf *data);

#endif
