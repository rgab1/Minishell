/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 19:21:58 by grivault          #+#    #+#             */
/*   Updated: 2026/06/18 19:02:20 by grivault         ###   ########.fr       */
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

static void	init_dummy_cmd(t_shell *shell)
{
	shell->cmd = malloc(sizeof(*shell->cmd)); // Allocate the struct
	if (!shell->cmd)
		return ;

	shell->cmd->cmd = malloc(sizeof(char *) * 3); // Allocate the args array
	if (!shell->cmd->cmd)
		return ;

	// Command setup:
	shell->cmd->cmd[0] = ft_strdup("export");
	
	// TEST 1: Test "export" with no arguments (Alphabetical print)
	shell->cmd->cmd[1] = NULL; 
	
	// TEST 2: Uncomment below to test adding a variable instead!
	// shell->cmd->cmd[1] = ft_strdup("NEW_VAR=hello_world"); 
	
	shell->cmd->cmd[2] = NULL;
}

int main(int ac, char **av, char **envp)
{
	t_shell	*shell;

	(void)ac;
	(void)av;
	shell = shell_init(envp);
	init_dummy_cmd(shell);
	export(shell);
	return (0);
}
