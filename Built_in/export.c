/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 21:09:27 by grivault          #+#    #+#             */
/*   Updated: 2026/06/18 05:58:29 by grivault         ###   ########.fr       */
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

void	print_env_alphabetical(t_env *env)
{
	t_env	**arr;
	t_env	*temp;
	size_t	count;
	size_t	i;
	size_t	j;

	if (!env)
		return ;
	count = get_env_size(env);
	arr = (t_env **)malloc(sizeof(t_env *) * count);
	if (!arr)
		return ; // Add your specific error exit here if you want

	/* 1. Fill the array with pointers */
	i = 0;
	temp = env;
	while (temp)
	{
		arr[i++] = temp;
		temp = temp->next;
	}

	/* 2. Bubble Sort the array of pointers */
	i = 0;
	while (i < count - 1)
	{
		j = 0;
		while (j < count - i - 1)
		{
			if (ft_strcmp(arr[j]->key, arr[j + 1]->key) > 0)
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}

	/* 3. Print in alphabetical order */
	i = 0;
	while (i < count)
	{
		if (arr[i]->value)
			ft_printf("declare -x %s=\"%s\"\n", arr[i]->key, arr[i]->value);
		else
			ft_printf("declare -x %s\n", arr[i]->key);
		i++;
	}
	free(arr);
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
