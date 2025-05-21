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

typedef struct s_node
{
    char *key;
    char *value;
    struct s_node *next;
} t_node;

int		ft_echo(char **argv);
int		ft_cd(char **argv);
int		ft_pwd(char **av)
t_node	*env_init(char **env);

#endif

