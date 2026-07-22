/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 05:17:59 by hassmou           #+#    #+#             */
/*   Updated: 2026/07/22 09:23:19 by hassmou          ###   ########.fr       */
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

void		manage_expand(t_tokens *tokens, t_shell *shell);
char		*set_newdata_token(t_exp *exp, t_tokens *tokens, t_shell *shell);
void		get_new_size_expand(t_exp *exp, t_tokens *tokens, t_shell *shell);

/*modify_str*/
void		modify_expand(t_exp *exp, const char *str, t_shell *shell);
void		modify_head_value(const char *str, t_exp *exp, size_t *shell);
void		modify_exit_status(t_exp *exp, char *final_str,int exit_code);
void		recursive_exit_status(t_exp *exp, int exit_code);

/*count_for_expand*/
void		count_expand(const char *str, t_exp *exp, t_shell *shell);
int			size_head_value(const char *str, t_exp *exp, t_shell *shell);
void		size_exit_status(t_exp *exp, t_shell *shell);

#endif
