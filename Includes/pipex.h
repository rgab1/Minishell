/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:46:43 by grivault          #+#    #+#             */
/*   Updated: 2026/07/06 00:07:52 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define DEFAULT_PATH "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin"

typedef struct s_cmd
{
	int				in_fd;
	int				out_fd;
	char			**cmd;
	struct s_cmd	*next;
}			t_cmd;

typedef struct s_shell	t_shell;

char	*get_path(t_shell *shell, char *cmd);

void	free_cmd_list(t_cmd *head);
void	free_split(char **split);
void	free_cmd(t_cmd *current);

int		is_builtin(t_shell *shell, int *pid);
void	master_function(t_shell *shell);
void	run_pipeline(t_shell *shell, int *pid);
void	run_command(t_cmd *current, char **envp, t_shell *shell);

void	print_list(t_cmd *head);
void	print_node(t_cmd *current);

#endif
