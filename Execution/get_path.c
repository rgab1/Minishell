/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhalmi <hrhalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:48:17 by grivault          #+#    #+#             */
/*   Updated: 2026/09/07 02:17:10 by hrhalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	**get_env_paths(t_shell *shell)
{
	char	*path;

	if (!shell || !shell->env)
		return (NULL);
	path = get_value("PATH", shell->env);
	if (!path)
		return (NULL);
	return (ft_split(path, ':'));
}

char	*get_path(t_shell *shell, char *cmd)
{
	int		i;
	char	**paths;
	char	*part;
	char	*full;

	if (!cmd || cmd[0] == '\0' || !ft_strcmp(cmd, ".") || !ft_strcmp(cmd, ".."))
		return (NULL);
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	paths = get_env_paths(shell);
	i = 0;
	while (paths && paths[i])
	{
		part = ft_strjoin(paths[i++], "/");
		full = ft_strjoin(part, cmd);
		free(part);
		if (full != NULL && access(full, F_OK | X_OK) == 0)
			return (free_split(paths), full);
		free(full);
	}
	return (free_split(paths), NULL);
}
