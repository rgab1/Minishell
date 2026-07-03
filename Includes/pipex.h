/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:46:43 by grivault          #+#    #+#             */
/*   Updated: 2026/07/04 00:40:15 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define DEFAULT_PATH "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin"

typedef struct s_cmd
{
	int				in_fd;
	int				out_fd;
	int				exit_status;
	char			**cmd;
	char			*tmp_file;
	struct s_cmd	*next;
}			t_cmd;

typedef struct s_shell t_shell;

#include <minishell.h>

char	*get_path(t_shell *shell, char *cmd);
char	**ft_split_quotes(char *s, char c);

void	free_all(t_shell *shell);
void	free_list(t_cmd *head);
void	free_split(char **split);
void	free_cmd(t_cmd *current);
void	full_cleanup(t_shell *shell);

int		is_builtin(t_shell *shell, int *pid);
void	master_function(t_shell *shell);
void	run_pipeline(t_shell *shell, int *pid);
void	run_command(t_cmd *current, char **envp, t_shell *shell);

void	print_list(t_cmd *head);
void	print_node(t_cmd *current);

#endif
