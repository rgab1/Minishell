/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 05:17:59 by hassmou           #+#    #+#             */
/*   Updated: 2026/07/23 14:28:37 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

typedef struct s_exp
{
	size_t	i;
	size_t	new_size;
	char	*final_str;
}			t_exp;

/*init_struct_exp*/
t_exp		*init_exp(void);

/*Expansion.c*/
void		manage_expand(t_tokens *tokens, t_shell *shell);
void		get_new_size_expand(t_exp *exp, t_tokens *tokens, t_shell *shell);
void		set_newdata_token(t_exp *exp, t_tokens *tokens, t_shell *shell);
void		free_exp(t_exp *exp);

/*modify_str.c*/
void		modify_expand(char *str, t_exp *exp, t_shell *shell);
void		modify_value(char *str, t_exp *exp, t_shell *shell);
void		add_expand(char *value, t_exp *exp);
void		modify_exit_status(t_exp *exp, int exit_code);
void		recursive_exit_status(size_t *new_size, char *final_str, int exit_code);

/*count_for_expand.c*/
void		count_expand(char *str, size_t *i, size_t *new_size,
				t_shell *shell);
int			size_head_value(char *str, size_t *i, t_shell *shell);
void		size_exit_status(size_t *i, size_t *new_size, t_shell *shell);

#endif
