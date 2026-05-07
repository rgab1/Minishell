/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:48:45 by grivault          #+#    #+#             */
/*   Updated: 2026/03/18 17:48:46 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <pipex.h>
#include <libft.h>

static t_cmd	*new_node(char **cmd)
{
	t_cmd	*node;

	node = (t_cmd *)malloc(sizeof(t_cmd));
	if (!node)
		return (NULL);
	node->in_fd = -1;
	node->out_fd = -1;
	node->cmd = cmd;
	node->next = NULL;
	return (node);
}

static void	in_out_files(char **av, t_cmd *head)
{
	int	infile_fd;
	int	outfile_fd;
	int	i;

	i = 2;
	infile_fd = open(av[1], O_RDONLY);
	if (infile_fd == -1)
		perror(av[1]);
	while (av[i + 1])
		i++;
	outfile_fd = open(av[i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile_fd == -1)
		perror(av[i]);
	head->in_fd = infile_fd;
	while (head->next)
		head = head->next;
	head->out_fd = outfile_fd;
}

t_cmd	*parsing(char **av)
{
	int		i;
	t_cmd	*head;
	t_cmd	*current;

	i = 2;
	current = NULL;
	head = NULL;
	while (av[i + 1])
	{
		if (!head)
		{
			head = new_node(ft_split_quotes(av[i++], ' '));
			current = head;
		}
		else
		{
			current->next = new_node(ft_split_quotes(av[i++], ' '));
			current = current->next;
		}
	}
	in_out_files(av, head);
	return (head);
}
