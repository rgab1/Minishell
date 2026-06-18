/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 21:09:27 by grivault          #+#    #+#             */
/*   Updated: 2026/06/18 05:40:24 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static size_t	env_count(t_env *env)
{
	size_t	i;

	i = 0;
	while (env)
	{
		env = env->next;
		i++;
	}
	return (i);
}


//a coder: print_env_alphabetical

int	export(t_shell *shell)
{
	size_t	i;
	char	**pair;

	i = 1;
	if (!shell->cmd->cmd[1])
		return (print_env_alphabetical(shell->env), 0);
	while (shell->cmd->cmd[i])
	{
		pair = extract_key_value(shell->cmd->cmd[i++]);
		set_value(pair[0], pair[1], &shell->env);
		free_strings(pair);
	}
	return (0);
}
