#ifndef MINISHELL_H
#define MINISHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <dirent.h>
#include <ctype.h>
#include <limits.h>
#include "libft/libft.h"
#include "readline/readline.h"
#include "readline/history.h"

#define BUFFER_SIZE 1024

extern int g_exit_status;

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

typedef struct s_node
{
    char *key;
    char *value;
    struct s_node *next;
} t_node;

int		ft_echo(char **argv);
int		ft_cd(char *command);
int		ft_pwd(char **av);
t_node	*env_init(char **env);
int     ft_unset(t_node **env, char *c_name);
void    env_add_back(t_node **env, t_node *new);
t_node  *env_add_new(char *key, char *value);
int     env_sort(t_node **env);
int     ft_strcmp(char *src, char *dest);
t_node  *return_address(char *str, t_node **env);
int     only_digit(char *str);
int		ft_export(char **av, t_node **env);
int     exec_external(char **cmd, char **env);
int     ft_search(char *str, t_node **env);
int     exec_cmd(char **cmd, t_node **env);
int     exec_builtin(char **cmd, t_node **env);
char    **find_paths(char **env);
char    *check_path(char *cmd, char **env);
int     ft_exit(char **av, t_node **env);
int     ft_env(t_node *env);
int     ft_search_env(char *str, t_node *env);
int     exec_pipes(t_cmd *cmds, t_node **env);
int     pipe_number(t_cmd *cmds);
void    swap_env_nodes(t_node *a, t_node *b);
int     exec_pipe(t_cmd *cmds, t_node **env);
t_cmd	*parse_tokens(t_token *tokens);
void	expand_cmds(t_cmd *cmds, t_node **env, int exit_status);
t_cmd	*new_cmd(void);
void	free_cmd_list(t_cmd *cmds);
char    *get_env_value(t_node *env, char *key);


#endif

