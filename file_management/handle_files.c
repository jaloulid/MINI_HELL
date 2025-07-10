/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoessedr <yoessedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 22:45:52 by yoessedr          #+#    #+#             */
/*   Updated: 2025/07/10 09:51:54 by yoessedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int    handle_files(t_redir *file, t_node **env)
{
    t_redir *redirect;

    redirect = file;
    while (redirect)
    {
        if (redirect->type == R_IN)
        {
            if (open_file(redirect->file, O_RDONLY) == -1)
                return (-1);
        }
        else if (redirect->type == R_OUT)
        {
            if (open_file(redirect->file, O_WRONLY | O_CREAT | O_TRUNC) == -1)
                return (-1);
        }
        else if (redirect->type == R_APPEND)
        {
            if (open_file(redirect->file, O_WRONLY | O_CREAT | O_APPEND) == -1)
                return (-1);
        }
        redirect = redirect->next;
    }
    return (0);
}

int open_file(const char *filename, int flags)
{
    int fd;

    fd = open(filename, flags, 0644);
    if (fd < 0)
    {
        perror("Error opening file");
        return (-1);
    }
    return (fd);
}
