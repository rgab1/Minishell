/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 19:21:58 by grivault          #+#    #+#             */
/*   Updated: 2026/06/18 17:53:51 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <minishell.h>
#include <built_in.h>

t_shell	*shell_init(char **envp)
{
	t_shell	*shell;

	shell = (t_shell *)malloc(sizeof(t_shell));
	if (!shell)
		return (exit_error("Code erreur a definir: malloc failed", 3), NULL);
	shell->env = env_init(envp);
	return (shell);
}

int main(int ac, char **av, char **envp)
{
	t_shell	*shell;

	(void)ac;
	(void)av;
	shell = shell_init(envp);
	env(shell);
	write(1, "\n", 1);
	export(shell);
	return (0);
}
