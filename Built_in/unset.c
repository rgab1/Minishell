/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 21:04:10 by grivault          #+#    #+#             */
/*   Updated: 2026/05/07 18:00:22 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	unset(t_shell *shell)
{
	if (ft_tablen(shell->cmd) != 2)
		exit_error("Error code a definir, cmd a pas le bon nombre d'arg", 3);
	del_env_node(&shell->env, shell->cmd[1]);
	exit(0);
}
