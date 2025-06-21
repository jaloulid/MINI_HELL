/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoessedr <yoessedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 22:28:01 by yoessedr          #+#    #+#             */
/*   Updated: 2025/06/21 17:23:38 by yoessedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>


int exec_pipes(t_cmd *cmds, char **env)
{
	int		pipe_fd[2];
	int		input_fd = 0;
	pid_t	pid;
	int		status;

	while (cmds)
	{
		if (cmds->next != NULL)
		{
			if (pipe(pipe_fd) == -1)
			{
				perror("pipe");
				return -1;
			}
		}
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			return -1;
		}
		else if (pid == 0)
		{
			if (input_fd != 0)
			{
				dup2(input_fd, STDIN_FILENO);
				close(input_fd);
			}
			if (cmds->next != NULL)
			{
				dup2(pipe_fd[1], STDOUT_FILENO);
				close(pipe_fd[0]);
				close(pipe_fd[1]);
			}
			exec_cmd(cmds->args, env);
			exit(EXIT_FAILURE); 
		}
		else
		{
			// Parent process
			if (input_fd != 0)
				close(input_fd);
			if (cmds->next != NULL)
			{
				close(pipe_fd[1]);
				input_fd = pipe_fd[0]; // for next command
			}
			waitpid(pid, &status, 0);
			cmds = cmds->next;
		}
	}
	return WEXITSTATUS(status);
}
