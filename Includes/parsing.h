/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 08:28:38 by hrhalmi           #+#    #+#             */
/*   Updated: 2026/06/05 17:47:59 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>

# define SINGLE_COT 39
# define DOUBLE_COT 34
# define ESPACE 32
// #define TAB	9

# define ERROR_SYNTAXE = "Syntaxe error"

typedef struct s_cmd	t_cmd;

typedef enum e_tokens_type
{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	HREDIR_IN,
	HREDIR_OUT,
}						t_token_type;

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
	char				*data;
	t_token_type		type;
	struct s_tokens		*head;
	struct s_tokens		*next;
}						t_tokens;

// browse_line.c
size_t					manage_lex(const char **s, size_t start);
size_t					index_in_cot(const char *str, size_t i, int car);

// create_tab.c
size_t					manage_count_cot(char const *s, size_t *i);
static size_t			count_word(char const *s);
static char				*ft_next_word(const char **s);
char					**split_star(char const *str);

// parse.c
int						ft_tokensize(t_tokens *lst);
static t_cmd			*init_cmd(int len_tok);
t_cmd					*create_cmd_struct(t_tokens *nodes);
t_cmd					*manage_cmd(t_tokens **tokens, t_cmd *cmd, int *j_tab);
void					add_str(t_tokens **tokens, t_cmd *cmd, int *j_tab);
int						change_fd(t_tokens **tokens, t_cmd *cmd, int redir);
void					put_cmd(t_cmd *cmd);

#endif
