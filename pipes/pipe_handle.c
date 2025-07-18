/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoessedr <yoessedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 22:28:01 by yoessedr          #+#    #+#             */
/*   Updated: 2025/07/11 15:09:53 by yoessedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>


static int	setup_pipe(int *pipe_fd)
{
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		return (-1);
	}
	return (0);
}

static void	child_process(t_cmd *cmds, int input_fd, int has_pipe, int *pipe_fd, t_node **env)
{
	if (input_fd != 0)
	{
		dup2(input_fd, STDIN_FILENO);
		close(input_fd);
	}
	if (has_pipe)
	{
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
	}
	if (handle_redirects(cmds) == -1)
		exit(EXIT_FAILURE);
	exec_cmd(cmds, env);
	exit(EXIT_FAILURE);
}

static void	parent_process(pid_t pid, int *input_fd, int has_pipe, int *pipe_fd)
{
	int	status;

	if (*input_fd != 0)
		close(*input_fd);
	if (has_pipe)
	{
		close(pipe_fd[1]);
		*input_fd = pipe_fd[0];
	}
	waitpid(pid, &status, 0);
}

int	exec_pipes(t_cmd *cmds, t_node **env)
{
	int		pipe_fd[2];
	int		input_fd = 0;
	int		has_pipe;
	pid_t	pid;

	while (cmds)
	{
		has_pipe = 0;
		if (cmds->next != NULL)
		{
			if (setup_pipe(pipe_fd) == -1)
				return (-1);
			has_pipe = 1;
		}
		pid = fork();
		if (pid == -1)
			return (perror("fork"), -1);
		if (pid == 0)
			child_process(cmds, input_fd, has_pipe, pipe_fd, env);
		else
			parent_process(pid, &input_fd, has_pipe, pipe_fd);
		cmds = cmds->next;
	}
	return (0);
}
