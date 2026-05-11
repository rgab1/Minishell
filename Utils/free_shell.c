/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 01:23:55 by grivault          #+#    #+#             */
/*   Updated: 2026/05/11 01:27:45 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <environment.h>
#include <minishell.h>
#include <pipex.h>

void	free_shell(t_shell *shell)
{
	free_env(shell->env);
	free_list(shell->cmd);
	free(shell);
}
