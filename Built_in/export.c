/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 21:09:27 by grivault          #+#    #+#             */
/*   Updated: 2026/05/02 21:51:24 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	print_env_alphabetical(t_env *head)
{
}

void	export(char	*key_and_value, t_env **head)
{
	if (key_and_value)
		new_env_node(head, extract_key_value(key_and_value));
	else
		print_env_alphabetical(*head);
}
