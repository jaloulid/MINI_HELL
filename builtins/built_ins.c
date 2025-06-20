/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoessedr <yoessedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 22:27:57 by yoessedr          #+#    #+#             */
/*   Updated: 2025/06/18 23:53:43 by yoessedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(char **argv)
{
    int newline;
    int i;
    int k;

    newline = 0;
    i = 1;
    k = 0;
    while(argv[i] && argv[i][k] == '-')
    {
        k = 1;
        while(argv[i][k] == 'n')
            k++;
        if(argv[i][k] == '\0')
        {
            newline = 1;
            i++;
            k = 0;
        }
    }
    while (argv[i])
    {
        ft_putstr_fd(argv[i], 1);
        if (argv[i + 1])
            ft_putchar_fd(' ', 1);
        i++;
    }
    if (!newline)
        ft_putchar_fd('\n', 1);
    return (0);
}

int	ft_cd(char *command)
{   
    char *path;

    if (command == NULL)
    {
        path = getenv("HOME");
        if (path == NULL)
        {
            ft_putstr_fd("cd: HOME not set\n", 2);
            return (1);
        }
    }
    else
        path = command;
    
    if (chdir(path) != 0)
    {
        perror("cd");
        return (1);
    }
    setenv("OLDPWD", getenv("PWD"), 1);
    setenv("PWD", getcwd(NULL, 0), 1);
    if (getenv("PWD") == NULL)
    {
        ft_putstr_fd("cd: PWD not set\n", 2);
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
	ft_putstr_fd(cwd, 1);
	ft_putstr_fd("\n", 1);
	return (0);
}

int ft_unset(t_node **env, char *c_name)
{
    t_node *current = *env;
    t_node *prev = NULL;

    while (current)
    {
        if (ft_strncmp(current->key, c_name, ft_strlen(c_name)) == 0 &&
            ft_strlen(current->key) == ft_strlen(c_name))
        {
            if (prev == NULL)
                current = current->next;
            else
                prev->next = current->next;

            free(current->key);
            free(current->value);
            free(current);
            return 0;
        }
        prev = current;
        current = current->next;
    }
    return 1;
}

int ft_export(char **av, t_node **env)
{
    int k;
    char *found;
    char *key;
    char *value;
    t_node *current = *env;
    if(!av[2])
        return(env_sort(env));
    found = ft_strchr(av[2], '=');
    k = found - av[2];
    key = ft_substr(av[2], 0, k);
    value = ft_strchr(av[2], '=') + 1;
    if (found)
	{
		while (current)
		{
			if (ft_strcmp(key, current->key) == 0)
			{
				free(current->value);
				current->value = ft_strdup(value);
				return(0);
			}
			current = current->next;
		}
		env_add_back(env, env_add_new(key, value));
    }
    return(0);
}
