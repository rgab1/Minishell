/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 01:49:31 by grivault          #+#    #+#             */
/*   Updated: 2026/07/06 00:04:18 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

typedef struct s_shell	t_shell;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

int		del_env_node(t_env **head, char *key);
void	new_env_node(t_env **head, char **key_and_value);
t_env	*env_init(char **envp);

void	free_env_node(t_env *node);
void	free_env(t_env *head);
void	free_envp(char **envp);

int		set_value(char *key, char *value, t_env **head);
int		is_valid_identifier(char *key);
char	*get_value(char *key, t_env *head);
char	**get_envp(t_shell *shell);
char	**extract_key_value(char *env_str);

#endif
