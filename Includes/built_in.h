/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 02:02:09 by grivault          #+#    #+#             */
/*   Updated: 2026/05/07 18:01:34 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BUILT_IN_H
# define BUILT_IN_H

# include <minishell.h>
# include <environment.h>

void	env(t_shell *shell);
void	pwd(t_shell *shell);
void	cd(t_shell *shell);

#endif
