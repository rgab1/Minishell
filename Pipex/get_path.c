/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:48:17 by grivault          #+#    #+#             */
/*   Updated: 2026/04/10 20:54:09 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <pipex.h>
#include <unistd.h>
#include <stdlib.h>

// Helper to grab the PATH array and save lines in get_path
static char	**get_env_paths(char **envp)
{
	int	i;

	i = 0;
	while (envp && envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp || !envp[i])
		return (ft_split(DEFAULT_PATH, ':'));
	return (ft_split(envp[i] + 5, ':'));
}

char	*get_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*part;
	char	*full;

	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	paths = get_env_paths(envp);
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
