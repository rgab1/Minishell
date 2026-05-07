/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:47:41 by grivault          #+#    #+#             */
/*   Updated: 2026/03/18 17:47:45 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pipex.h>

void	print_node(t_cmd *current)
{
	int	i;

	i = 0;
	printf("indice = %d\n", i);
	printf("in_fd = %d\n", current->in_fd);
	printf("out_fd = %d\n", current->out_fd);
	printf("cmd = %s\n", current->cmd[0]);
	printf("\n");
}

void	print_list(t_cmd *head)
{
	int	i;

	i = 0;
	while (head)
	{
		printf("indice = %d\n", i);
		printf("in_fd = %d\n", head->in_fd);
		printf("out_fd = %d\n", head->out_fd);
		printf("cmd = %s\n", head->cmd[0]);
		printf("\n");
		head = head->next;
	}
}
