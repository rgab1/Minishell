/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 08:28:38 by hrhalmi           #+#    #+#             */
/*   Updated: 2026/05/12 06:40:18 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

#define SINGLE_COT 39
#define DOUBLE_COT 34
#define ESPACE 32
// #define TAB	9

typedef enum e_tokens_type
{
	WORD,
	CMD,
	FLAGS,
	ARGS,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	HREDIR_IN,
	HREDIR_OUT,
}					t_token_type;

// typedef struct  s_lexer
// {
//     char    *word;
//     char    *cmd;
//     char    *flags;
//     char    direction;
//     int     pipe;
//     s_lexer *next;
//     t_token_type    type;
// }               t_lexer;

typedef struct s_tokens
{
	char			*data;
	t_token_type	type;
	struct s_tokens	*head;
	struct s_tokens	*next;
}					t_tokens;


#endif
