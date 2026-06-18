/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 14:24:14 by grivault          #+#    #+#             */
/*   Updated: 2026/06/18 05:23:46 by grivault         ###   ########.fr       */
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

char	**get_envp(t_shell *shell)
{
	size_t	i;
	char	**envp;
	t_env	*current;
	char	*partial_variable;

	envp = (char **)malloc(sizeof(char *) * (env_count(shell->env) + 1));
	if (!envp)
		exit_error("Malloc failed", 4);
	current = shell->env;
	i = 0;
	while (current)
	{
		partial_variable = ft_strjoin(current->key, "=");
		if (current->value)
			envp[i] = ft_strjoin(partial_variable, current->value);
		else
			envp[i] = ft_strdup(partial_variable);
		free(partial_variable);
		i++;
		current = current->next;
	}
	envp[i] = NULL;
	return (envp);
}
