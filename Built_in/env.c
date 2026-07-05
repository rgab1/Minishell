/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 18:40:49 by grivault          #+#    #+#             */
/*   Updated: 2026/07/05 23:55:04 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	env(t_shell *shell)
{
	t_env	*head;

	if (shell->cmd->cmd[1])
		return (minishell_error("env", ERROR_MANY_ARGS), 127);
	head = shell->env;
	while (head)
	{
		if (head->value)
			ft_printf("%s=%s\n", head->key, head->value);
		head = head->next;
	}
	return (0);
}
