/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 02:02:09 by grivault          #+#    #+#             */
/*   Updated: 2026/05/11 03:06:18 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BUILT_IN_H
# define BUILT_IN_H

# include <minishell.h>

int	env(t_shell *shell);
int	pwd(t_shell *shell);
int	cd(t_shell *shell);
int	unset(t_shell *shell);
int	export(t_shell *shell);
int	echo(t_shell *shell);

#endif
