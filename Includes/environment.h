/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 01:49:31 by grivault          #+#    #+#             */
/*   Updated: 2026/05/01 02:59:23 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

typedef struct	s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

# include <minishell.h>


int		del_env_node(t_env **head, char *key);
void	new_env_node(t_env **head, char **key_and_value);
t_env	*env_init(char **envp);
void	free_env_node(t_env *node);
void	free_env(t_env *head);

#endif
