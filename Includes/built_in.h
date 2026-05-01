/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 02:02:09 by grivault          #+#    #+#             */
/*   Updated: 2026/05/01 02:07:10 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BUILT_IN_H
# define BUILT_IN_H

# include <minishell.h>
# include <environment.h>

void	env(t_env *head);
void	pwd(t_env *head);
void	cd(char *path, t_env *head);

#endif
