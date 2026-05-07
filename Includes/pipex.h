/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:46:43 by grivault          #+#    #+#             */
/*   Updated: 2026/03/18 17:46:45 by grivault         ###   ########.fr       */
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

t_cmd	*parsing(char **av);
void	print_list(t_cmd *head);
void	print_node(t_cmd *current);
void	run_command(t_cmd *current, char **envp, t_cmd *head);
void	free_split(char **split);
char	*get_path(char *cmd, char **envp);
void	free_list(t_cmd *head);
void	run_pipeline(t_cmd *current, char **envp, int *pid);
char	**ft_split_quotes(char *s, char c);

#endif
