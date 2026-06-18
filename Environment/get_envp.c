/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 14:24:14 by grivault          #+#    #+#             */
/*   Updated: 2026/06/05 14:44:01 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell>

static size_t	env_count(t_env *env)
{
	size_t	i;

	if (env)
		i = 1;
	while (env->next)
	{
		env = env->next;
		i++;
	}
}

char	**get_envp(t_shell *shell)
{
	size_t	i;
	char	**envp;
	t_env	*current;
	char	*partial_variable;

	envp = (char **)malloc(sizeof(char *) * (env_count(shell) + 1));
	if (!envp)
		exit_error("Malloc failed", 4);
	i = 0;
	while (current)
	{
		partial_variable = ft_strjoin(current->key, "=");
		envp[i] = ft_strjoin(partial_variable, current->value);
		free(partial_variable);
		i++;
	}
	envp[i] = NULL;
	return (envp);
}
