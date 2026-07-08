/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:46:43 by grivault          #+#    #+#             */
/*   Updated: 2026/07/08 19:40:16 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H
# define DEFAULT_PATH "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin"

#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

typedef struct s_cmd
{
	char			**cmd;
	int				in_fd;
	int				out_fd;
	char			*namefile;
	struct s_cmd	*next;
}			t_cmd;

typedef struct s_shell	t_shell;

char	*get_path(t_shell *shell, char *cmd);

void	free_cmd_list(t_cmd *head);
void	free_split(char **split);
void	free_cmd(t_cmd *current);

int		is_builtin(t_shell *shell, int *pid);
void	execution(t_shell *shell);
void	run_pipeline(t_shell *shell, int *pid);
void	run_command(t_cmd *current, char **envp, t_shell *shell);

void	print_list(t_cmd *head);
void	print_node(t_cmd *current);

#endif
