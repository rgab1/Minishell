/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 18:08:29 by grivault          #+#    #+#             */
/*   Updated: 2026/05/11 03:04:51 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*path_resolution(char *path, t_env *head)
{
	char	*home_path;
	char	*old_pwd;

	home_path = get_value("HOME", head);
	if (!path)
	{
		if (!home_path)
			return (ft_putstr_fd("minishell: cd: HOME not set\n", 2), NULL);
		return (ft_strdup(home_path));
	}
	if (path[0] == '~')
	{
		if (!home_path)
			return (ft_putstr_fd("minishell: cd: HOME not set\n", 2), NULL);
		return (ft_strjoin(home_path, path + 1));
	}
	if (ft_strncmp(path, "-", 2) == 0)
	{
		old_pwd = get_value("OLDPWD", head);
		if (!old_pwd)
			return (ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2), NULL);
		return (ft_strdup(old_pwd));
	}
	return (ft_strdup(path));
}

static void	update_wd_vars(t_env **head)
{
	char	*new_cwd;

	set_value("OLDPWD", get_value("PWD", *head), head);
	new_cwd = getcwd(NULL, 0);
	if (new_cwd)
	{
		set_value("PWD", new_cwd, head);
		free(new_cwd);
	}
	else
		perror("minishell: cd");
}

int	cd(t_shell *shell)
{
	char	*path;

	path = path_resolution(shell->cmd->cmd[1], shell->env);
	if (!path)
		return (1);
	if (chdir(path) != 0)
		return (perror("minishell: cd"), free(path), 1);
	if (shell->cmd->cmd[1] && ft_strncmp(shell->cmd->cmd[1], "-", 2) == 0)
		ft_printf("%s\n", path);
	update_wd_vars(&shell->env);
	free(path);
	return (0);
}
