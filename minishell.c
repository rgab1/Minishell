/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 19:21:58 by grivault          #+#    #+#             */
/*   Updated: 2026/05/01 02:27:55 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <minishell.h>
#include <built_in.h>

int main(int ac, char **av, char **envp)
{
	t_env	*head_env;

	(void)ac;
	(void)av;
	head_env = env_init(envp);
	env(head_env);
	return (0);
}
