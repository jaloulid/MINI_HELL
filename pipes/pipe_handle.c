/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoessedr <yoessedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 22:28:01 by yoessedr          #+#    #+#             */
/*   Updated: 2025/06/21 00:34:57 by yoessedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int exec_pipe(t_cmd *cmds, t_node **env)
{
    int pipe_fd[2];
    pid_t pid;
    int status;

    if (pipe(pipe_fd) == -1)
    {
        perror("pipe");
        return -1;
    }

    pid = fork();
    if (pid < 0)
    {
        perror("fork");
        close(pipe_fd[0]);
        close(pipe_fd[1]);
        return -1;
    }
    else if (pid == 0) // Child process
    {
        dup2(pipe_fd[1], STDOUT_FILENO);
        close(pipe_fd[0]);
        close(pipe_fd[1]);
        exec_cmd(cmds->args, env);
        exit(EXIT_FAILURE);
    }
    else // Parent process
    {
        close(pipe_fd[1]);
        waitpid(pid, &status, 0);
        dup2(pipe_fd[0], STDIN_FILENO);
        close(pipe_fd[0]);
        return WEXITSTATUS(status);
    }
}
int exec_pipes(t_cmd *cmds, t_node **env)
{
    int status = 0;

    while (cmds)
    {
        status = exec_pipe(cmds, env);
        if (status < 0)
        {
            perror("Execution failed");
            return -1;
        }
        cmds = cmds->next;
    }
    return status;
}
