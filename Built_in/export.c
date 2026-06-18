/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 21:09:27 by grivault          #+#    #+#             */
/*   Updated: 2026/06/18 18:10:11 by grivault         ###   ########.fr       */
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

static void	env_bubble_sort(t_env **arr)
{
	int		swapped;
	size_t	i;
	t_env	*temp;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (arr[i] && arr[i + 1])
		{
			if (ft_strcmp(arr[i]->key, arr[i + 1]->key) > 0)
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				swapped = 1;
			}
			i++;
		}
	}
}

static void	print_sorted_arr(t_env **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i]->value)
			ft_printf("declare -x %s=\"%s\"\n", arr[i]->key, arr[i]->value);
		else
			ft_printf("declare -x %s\n", arr[i]->key);
		i++;
	}
}

void	print_env_alphabetical(t_env *env)
{
	t_env	**arr;
	t_env	*temp;
	size_t	i;

	if (!env)
		return ;
	arr = (t_env **)malloc(sizeof(t_env *) * (env_count(env) + 1));
	if (!arr)
		return (exit_error("Malloc failed", 4));
	i = 0;
	temp = env;
	while (temp)
	{
		arr[i++] = temp;
		temp = temp->next;
	}
	arr[i] = NULL;
	env_bubble_sort(arr);
	print_sorted_arr(arr);
	free(arr);
}

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
