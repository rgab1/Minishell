/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 01:49:31 by grivault          #+#    #+#             */
/*   Updated: 2026/05/01 02:07:58 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include <minishell.h>

int		del_env_node(t_env **head, char *key);
t_env	*new_env_node(t_env *head, char **key_and_value);
t_env	*env_init(char **envp);

#endif
