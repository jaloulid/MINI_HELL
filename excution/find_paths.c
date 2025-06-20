/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoessedr <yoessedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 22:27:46 by yoessedr          #+#    #+#             */
/*   Updated: 2025/06/21 00:18:29 by yoessedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
char **find_paths(char **env)
{
    char *path = NULL;
    char **paths = NULL;
    int i = 0;

    if (!env || !*env)
        return (NULL);
    while (env[i])
    {
        if (ft_strncmp(env[i], "PATH=", 5) == 0)
        {
            path = ft_strdup(env[i] + 5);
            break;
        }
        i++;
    }
    if (!path)
        return (NULL);
    paths = ft_split(path, ':');
    free(path);
    return (paths);
}
char *check_path(char *cmd, char **env)
{
    char **paths = find_paths(env);
    char *full_path = NULL;
    int i = 0;

    if (!paths)
        return (NULL);
    while (paths[i])
    {
        full_path = ft_strjoin(paths[i], "/");
        full_path = ft_strjoin(full_path, cmd);
        if (access(full_path, X_OK) == 0)
        {
            free(paths);
            return (full_path);
        }
        free(full_path);
        i++;
    }
    free(paths);
    return (NULL);
}
int pipe_number(t_cmd *cmds)
{
    int count = 0;

    while (cmds)
    {
        count++;
        cmds = cmds->next;
    }
    return (count);
}
