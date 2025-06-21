/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoessedr <yoessedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 17:32:18 by yoessedr          #+#    #+#             */
/*   Updated: 2025/06/21 16:18:50 by yoessedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	exec_cmd(t_cmd *cmd, t_env *env)
// {
// 	if (cmd->type == CMD_BUILTIN)
// 	{
// 		exec_builtin(cmd, env);
// 	}
// 	else if (cmd->type == CMD_EXTERNAL)
// 	{
// 		exec_external(cmd, env);
// 	}
// 	else
// 	{
// 		fprintf(stderr, "Unknown command type\n");
// 		exit(EXIT_FAILURE);
// 	}
// }
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
int exec_cmd(char **cmd, char **env)
{
	if (!cmd || !cmd[0])
	{
		fprintf(stderr, "No command provided\n");
		return -1;
	}
	char *path = check_path(cmd[0], env);
	if (path)
		cmd[0] = path;
		else
		{
			fprintf(stderr, "Command not found: %s\n", cmd[0]);
			return -1;
		}
	if (ft_search(cmd[0], env) >= 0)
		return exec_builtin(cmd, env);
	else
		return exec_external(cmd, NULL);
}

int ft_search(char *str,char  **env)
{

	while (*env)
	{
		if (strncmp(*env, str, strlen(str)) == 0 && (*env)[strlen(str)] == '=')
			return 0;
		env++;
	}
	return -1;
}
