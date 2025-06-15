/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaloulid <jaloulid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 06:05:49 by jaloulid          #+#    #+#             */
/*   Updated: 2025/06/02 19:14:55 by jaloulid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/history.h>
# include <unistd.h>
# include <readline/readline.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "libft/libft.h"

//LEXER STRUCT
typedef enum e_token_type
{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	HEREDOC
}	t_token_type;

typedef struct s_token
{
	char			*value;
	t_token_type	type;
	struct s_token	*next;
}	t_token;

//lexer functions
t_token	*lexer(char *line);
t_token *new_token(char *value, t_token_type type);
void	add_back(t_token **list, t_token *new);
t_token_type	get_token_type(char *s);
int get_word_len(char *line);
void    handle_word(char *line, int *i, t_token **list);
void    free_token_list(t_token *list);
void    handle_operator(char *line, int *i, t_token **list);

//PARSER STRUCTER
typedef enum e_redir_type
{
	// REDIR_IN,
	// REDIR_OUT,
	// REDIR_APPEND,
	R_IN,
	R_OUT,
	R_APPEND,
	R_HEREDOC
}	t_redir_type;

typedef struct s_redir
{
	char	*file;
	t_redir_type type;
	struct s_redir *next;
}	t_redir;

typedef struct s_cmd
{
	char	**args;
	t_redir	*redirect;
	struct	s_cmd *next;	
}	t_cmd;

//envirement struct
typedef struct s_node
{
    char *key;
    char *value;
    struct s_node *next;
} t_node;

//envirement functions
t_node  *env_add_new(char *key, char *value);
t_node	*env_add_back(t_node *env, t_node *new);
t_node *env_init(char **env);
char    *get_env_value(t_node *env, char *key);

//expand_functions
char    *expand_var(char *str, t_node *env, int last_exit);
char    *expand_dollar(const char *str, int *i, t_node *env, int last_exit);
char    *append_char(char *base, char c);
char    *append_str(char *base, char *add);
void    expand_cmds(t_cmd *cmds, t_node *env, int status);

//PARSER FUNCTIONS
t_redir *new_redir(char *file, t_redir_type type);
t_cmd   *new_cmd(void);
void    cmd_add_back(t_cmd **lst, t_cmd *new);
void    redir_add_back(t_redir **lst, t_redir *new);
void    free_cmd_list(t_cmd *cmd);
void    collect_arg(t_cmd *cmd, char *value);
t_cmd   *parse_tokens(t_token *tokens);
int is_redirect(t_token *token);
int parse_redirect_token(t_token **tokens, t_cmd *cmd, t_cmd **cmds);
void    parse_word_token(t_token **tokens, t_cmd *cmd);
void    parse_init_cmd(t_cmd **current, t_cmd **cmds);
void    parse_handle_pipe(t_cmd **current);

// Debug tools
// void    print_cmds(t_cmd *cmds);
// void    print_redirs(t_redir *redir);
// void    parse_word_token(t_token **tokens, t_cmd *cmd);

#endif