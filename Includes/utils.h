/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhalmi <hrhalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 17:06:25 by hrhalmi           #+#    #+#             */
/*   Updated: 2026/09/11 18:20:34 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/*free_cmd_star.c*/
void	free_cmd_struct(t_cmd *cmd);
void	free_cmd_star(t_cmd *cmd);

/*free_exp.c*/
void	free_exp(t_exp *exp);

/*free_lex*/
void	free_tokens(t_tokens *tokens);

/*free_tokens.c*/
void	free_tokens(t_tokens *tokens);
void	free_tokens_error(t_tokens *tokens, t_shell *shell);

/*ft_getuid.c*/
int		ft_getuid(void);

/*full_cleanup.c*/
void	full_cleanup(t_shell *shell);

/*minishell_error.c*/
void	minishell_error(char *context, char *error_msg, char *failed_str);

#endif
