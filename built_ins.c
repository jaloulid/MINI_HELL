#include "minishell.h"

int	ft_echo(char **argv)
{
    int newline;
    int i;

    newline = 1;
    i = 1;
    if(argv[1] && ft_strncmp(argv[1], "-n", 2) == 0)
    {
        newline = 0;
        i++;
    }
    while (argv[i])
    {
        ft_putstr(argv[i]);
        if (argv[i + 1])
            ft_putchar(' ');
        i++;
    }
    if (newline)
        ft_putchar('\n');
}

int	ft_cd(char *command)
{   
    char *path;

    if (argv[1] == NULL)
    {
        path = getenv("HOME");
        if (path == NULL)
        {
            ft_putstr("cd: HOME not set\n");
            return (1);
        }
    }
    else
        path = argv[1];
    
    if (chdir(path) != 0)
    {
        perror("cd");
        return (1);
    }
    setenv("OLDPWD", getenv("PWD"), 1);
    setenv("PWD", getcwd(NULL, 0), 1);
    if (getenv("PWD") == NULL)
    {
        ft_putstr("cd: PWD not set\n");
        return (1);
    }
	return (0);
}

int	ft_pwd(char **av)
{
	char *cwd;
	(void)av;

	cwd = getcwd(NULL, 0);
	if(!cwd)
		return(perror("pwd"), 1);
	ft_putstr(cwd);
	ft_putstr("\n");
	return (0);
}

int	ft_unset(char *c_name)
{
    t_node *env;
    t_node *copy;
    env = malloc(sizeof(t_node));
    copy = env;

    while(copy)
    {
        if(ft_strncmp(copy->next->key, c_name, ft_strlen(copy->key)))
            copy = copy->next;
        else
            break;
    }
    if(copy->next == NULL && ft_strncmp(copy->key, c_name, ft_strlen(copy->key)))
        return(1);
    else
    {
        copy = copy->next->next;
        copy->next = NULL;
    }
    return(0);
}
