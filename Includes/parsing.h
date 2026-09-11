/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhalmi <hrhalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 08:28:38 by hrhalmi           #+#    #+#             */
/*   Updated: 2026/09/11 17:59:36 by hrhalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# define SINGLE_COT 39
# define DOUBLE_COT 34
# define ESPACE 32

typedef enum e_tokens_type
{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	HREDIR_IN,
	AREDIR_OUT,
}					t_token_type;

typedef struct s_tokens
{
	char			*data;
	t_token_type	type;
	long long int	was_quotes;
	struct s_tokens	*next;
}					t_tokens;

// lexing.c
void				search_symbols(char const *s, size_t *i, size_t *count);
void				search_redir_in(char const *s, size_t *i, size_t *count);
void				search_redir_out(char const *s, size_t *i, size_t *count);
void				search_pipe(char const *s, size_t *i, size_t *count);

// init_token.c
t_tokens			*create_tokens(char *str, t_token_type type);
void				ft_lstadd_token(t_tokens **lst, t_tokens *new);
t_tokens			*compare_for_create_token(char **tab, int i);
t_tokens			*manage_token(char **tab, t_shell *shell);
int					expand_tokens(t_tokens *tokens, t_shell *shell);

// remove_quotes_from_heredoc
void				remove_quotes(char **str);
void				browse_quotes(char *new_str, char *str);
void				change_in_sq(int *in_sq, size_t *i);
void				change_in_dq(int *in_dq, size_t *i);

// browse_line.c
size_t				manage_lex(const char **s, size_t start);

// create_tab.c
void				index_count_cot(char const *s, size_t *i);
size_t				count_word(char const *s);
char				*ft_next_word(const char **s);
char				**split_star(char const *str);

// parse.c
t_cmd				*init_cmd(int len_tok);
t_cmd				*create_cmd_struct(t_tokens *nodes, t_shell *shell);
int					manage_pipe(t_tokens **nodes, t_cmd **cmd, int *j_tab);
t_cmd				*manage_cmd(t_tokens **tokens, t_shell *shell, int *j_tab,
						int *i_heredoc);
int					sort_redir(t_tokens **tokens, t_shell *shell,
						int *i_heredoc);

// check_syntaxe.c
int					check_syntax(t_tokens *tokens);
void				clear_impostor_tokens(t_tokens **current);

// parse_utils.c
int					ft_tokensize(t_tokens *lst);
void				add_str(t_tokens **tokens, t_cmd *cmd, int *j_tab);

// repair_fd.c
void				repair_fd_in(int fd, t_cmd *cmd);
void				repair_fd_out(int fd, t_cmd *cmd);

// change_fd.c
int					manage_fd(t_tokens **tokens, t_shell *shell,
						int *i_heredoc);
int					change_fd_redir(t_tokens **tokens, size_t redir,
						t_cmd *cmd);
int					change_fd_aredir_out(t_tokens **tokens, t_cmd *cmd);
int					change_fd_hredir_in(t_tokens **tokens, t_shell *shell,
						int *i_heredoc);
int					change_heredoc_extension(t_tokens **tokens, t_shell *shell,
						char *namefile);

// change_fd_heredoc
int					make_heredoc(t_tokens **tokens, t_shell *shell);
char				*name_file_hc(int *i_heredoc);
int					line_null_by_sigint_heredc(char *line);
void				manage_expand_heredc(t_tokens **tokens, t_shell *shell,
						char *line);

/*
char				*get_key(unsigned char *src, t_env *env, int *i);
int					ft_is_key(char *key, t_env *head);
int					ft_is_env(char c);
*/

// garbage
void				print_lst(t_tokens *nodes);

#endif
