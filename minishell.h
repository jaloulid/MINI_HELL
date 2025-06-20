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

extern int g_exit_status;


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
int     ft_search_env(char *str, t_node **env);


#endif

