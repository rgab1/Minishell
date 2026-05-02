/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 18:08:29 by grivault          #+#    #+#             */
/*   Updated: 2026/05/02 20:48:31 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <built_in.h>

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
		ft_printf("%s\n", old_pwd);
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

void	cd(char *path, t_env **head)
{
	path = path_resolution(path, *head);
	if (!path)
		return ;
	if (chdir(path) != 0)
		perror("minishell: cd");
	else
		update_wd_vars(head);
	free(path);
}
