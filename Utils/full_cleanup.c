/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_cleanup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 22:59:26 by grivault          #+#    #+#             */
/*   Updated: 2026/08/22 18:08:01 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	full_cleanup(t_shell *shell)
{
	if (!shell)
		exit_error(ERROR_SHELL_NDEF_5, 5);
	if (shell->env)
		free_env(shell->env);
	if (shell->cmd)
		free_cmd_struct(shell->cmd);
	if (shell->save_in > 2)
		close(shell->save_in);
	if (shell->save_out > 2)
		close(shell->save_out);
	free(shell);
}
