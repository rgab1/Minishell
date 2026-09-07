/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_uid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhalmi <hrhalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 14:39:56 by hrhalmi           #+#    #+#             */
/*   Updated: 2026/09/07 02:19:19 by hrhalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	modify_uid(t_exp *exp, t_shell *shell)
{
	int		i;
	char	*str_uid;

	i = 0;
	str_uid = ft_itoa(shell->uid);
	exp->i += 4;
	while (str_uid[i])
		exp->final_str[exp->new_size++] = str_uid[i++];
	free(str_uid);
}
