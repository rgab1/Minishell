/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 08:28:38 by hrhalmi           #+#    #+#             */
/*   Updated: 2026/07/16 17:48:20 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "environment.h"
# include "execution.h"
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
	AREDIR_OUT,
}						t_token_type;

typedef struct s_tokens
{
	char				*data;
	t_token_type		type;
	struct s_tokens		*next;
}						t_tokens;

// lexing.c
void					search_symbols(char const *s, size_t *i, size_t *count);
void	search_redir_in(char const *s, size_t *i, size_t *count);
void	search_redir_out(char const *s, size_t *i, size_t *count);
void	search_pipe(char const *s, size_t *i, size_t *count);

// init_token.c
t_tokens				*create_tokens(char *str, t_token_type type);
void					ft_lstadd_token(t_tokens **lst, t_tokens *new);
t_tokens				*manage_token(char **tab);

// browse_line.c
size_t					manage_lex(const char **s, size_t start, t_env *env);
size_t					index_in_cot(const char *str, size_t i, int car,
							t_env *env);

// create_tab.c
void					manage_count_cot(char const *s, size_t *i);
size_t					count_word(char const *s);
char					*ft_next_word(const char **s, t_env *env);
char					**split_star(char const *str, t_env *env);

// parse.c
t_cmd					*init_cmd(int len_tok);
t_cmd					*create_cmd_struct(t_tokens *nodes);
int						manage_pipe(t_tokens **nodes, t_cmd **cmd, int *j_tab);
t_cmd					*manage_cmd(t_tokens **tokens, t_cmd *cmd, int *j_tab);
int						sort_redir(t_tokens **tokens, t_cmd *cmd);

// parse_utils.c
int						ft_tokensize(t_tokens *lst);
void					add_str(t_tokens **tokens, t_cmd *cmd, int *j_tab);
void					put_cmd(t_cmd *cmd);

// repair_fd.c
void					repair_fd_in(int fd, t_cmd *cmd);
void					repair_fd_out(int fd, t_cmd *cmd);

// change_fd.c
int						manage_fd(t_tokens **tokens, t_cmd *cmd, int redir);
int						change_fd_redir_in(t_tokens **tokens, t_cmd *cmd);
int						change_fd_redir_out(t_tokens **tokens, t_cmd *cmd);
int						change_fd_aredir_out(t_tokens **tokens, t_cmd *cmd);

// exit_free.c
void					exit_free(t_tokens *token, t_cmd *cmd, char *str);
void					free_tokens(t_tokens *token);
void					free_cmd(t_cmd *cmd);

// env.c
int						count_va_env(const char *str, size_t *i, t_env *env,
							size_t *supp);
char					*get_key(unsigned char *src, t_env *env, int *i);
int						ft_is_key(char *key, t_env *head);
int						ft_is_env(char c);

// garbage
void					print_lst(t_tokens *nodes);
#endif
