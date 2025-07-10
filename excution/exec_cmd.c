/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoessedr <yoessedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 17:32:18 by yoessedr          #+#    #+#             */
/*   Updated: 2025/07/10 09:58:16 by yoessedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int exec_external(char **cmd, char **env)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
	{
		perror("Fork failed");
		return -1;
	}
	else if (pid == 0)
	{
		if (execve(cmd[0], cmd, env) < 0)
		{
			perror("Execve failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			return WEXITSTATUS(status);
	}
	return 0;
}
int exec_builtin(char **cmd, t_node **env)
{
	if (strcmp(cmd[0], "cd") == 0)
		return (ft_cd(cmd[1]));
	else if (strcmp(cmd[0], "echo") == 0)
		return (ft_echo(cmd));
	else if (strcmp(cmd[0], "exit") == 0)
		exit(EXIT_SUCCESS);
	else if (strcmp(cmd[0], "pwd") == 0)
		return (ft_pwd(cmd));
	else if (strcmp(cmd[0], "env") == 0)
		return (ft_env(*env));
	else if (strcmp(cmd[0], "export") == 0)
		return (ft_export(cmd, env));
	else if (strcmp(cmd[0], "unset") == 0)
		return (ft_unset(env, cmd[1]));
	else
	{
		fprintf(stderr, "Unknown builtin command: %s\n", cmd[0]);
		return -1;
	}
}
int exec_cmd(char **args, t_node **env)
{
	if (!args || !args[0])
	{
		fprintf(stderr, "No command provided\n");
		return -1;
	}
	char *path = check_path(args[0], env);
	if (path)
		args[0] = path;
		else
		{
			fprintf(stderr, "Command not found: %s\n", args[0]);
			return -1;
		}
	if(*(args)->redir->type != NULL && *args->redir->file != NULL )
	{
		if (handle_files(args, env) == -1)
		{
			fprintf(stderr, "Error handling files\n");
			return -1;
		}
	}
	if ((!is_builtin(args[0])) == 0)
		return (exec_builtin(args, env));
	else
	{
		char **env_array = env_list_to_array(env);
		return exec_external(args, env_array);
	}
}

int is_builtin(char *cmd)
{
	if (!cmd)
		return 0;
	return (!strcmp(cmd, "cd") ||
			!strcmp(cmd, "echo") ||
			!strcmp(cmd, "pwd") ||
			!strcmp(cmd, "exit") ||
			!strcmp(cmd, "env") ||
			!strcmp(cmd, "export") ||
			!strcmp(cmd, "unset"));
}

