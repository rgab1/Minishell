/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 18:40:49 by grivault          #+#    #+#             */
/*   Updated: 2026/05/11 03:05:11 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	env(t_shell *shell)
{
	t_env	*head;

	head = shell->env;
	while (head)
	{
		ft_printf("%s=%s\n", head->key, head->value);
		head = head->next;
	}
	return (0);
}
