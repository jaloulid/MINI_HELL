/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoessedr <yoessedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 17:32:18 by yoessedr          #+#    #+#             */
/*   Updated: 2025/07/13 21:51:00 by yoessedr         ###   ########.fr       */
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
			g_exit_status = 127;
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &g_exit_status, 0);
		if (WIFEXITED(status))
			return WEXITSTATUS(status);
	}
	return 0;
}
int exec_builtin(char **cmd, t_node **env)
{
	if (ft_strcmp(cmd[0], "cd") == 0)
		return (ft_cd(cmd[1]));
	else if (ft_strcmp(cmd[0], "echo") == 0)
		return (ft_echo(cmd));
	else if (ft_strcmp(cmd[0], "exit") == 0)
		exit(EXIT_SUCCESS);
	else if (ft_strcmp(cmd[0], "pwd") == 0)
		return (ft_pwd(cmd));
	else if (ft_strcmp(cmd[0], "env") == 0)
		return (ft_env(*env));
	else if (ft_strcmp(cmd[0], "export")== 0)
		return (ft_export(cmd, env));
	else if (ft_strcmp(cmd[0], "unset") == 0)
		return (ft_unset(env, cmd[1]));
	else
	{
		ft_putstr_fd("Unknown builtin command:", 2);
		ft_putendl_fd(cmd[0], 2);
		g_exit_status = 127;
	}
	return(g_exit_status);
}
int	handle_redirects(t_cmd *arg, t_node **env)
{
	if (arg && arg->redirect && arg->redirect->type && arg->redirect->file)
	{
		if (handle_files(arg->redirect, env) == -1)
		{
			fprintf(stderr, "Error handling files\n");
			return (-1);
		}
	}
	return (0);
}

int	run_builtin(t_cmd *arg, t_node **env, char **args)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		if (handle_redirects(arg, env) == -1)
			exit(1);
		exit(exec_builtin(args, env));
	}
	waitpid(pid, &g_exit_status, 0);
	return (0);
}

int	validate_external_command(char **args, t_node **env)
{
	char	*path;

	if (args[0][0] != '/')
	{
		path = check_path(args[0], env);
		if (path)
			args[0] = path;
		else
		{
			ft_putstr_fd("Command not found :", 2);
			ft_putendl_fd(args[0],2);
			g_exit_status = 127;
		}
	}
	else if (access(args[0], F_OK) == -1)
	{
		ft_putstr_fd("Command not found :", 2);
		ft_putendl_fd(args[0],2);
		g_exit_status = 127;
		return (-1);
	}
	return (0);
}

int	exec_cmd(t_cmd *arg, t_node **env)
{
	char	**args;
	char	**env_array;

	args = arg->args;
	if (!args || !args[0])
	{
		ft_putendl_fd("No command provided", 2);
		g_exit_status = 127;
	}
	if (is_builtin(args[0]))
		return (run_builtin(arg, env, args));
	if (validate_external_command(args, env) == -1)
		return (-1);
	if (handle_redirects(arg, env) == -1)
		return (-1);
	env_array = env_list_to_array(env);
	return (exec_external(args, env_array));
}


int is_builtin(char *cmd)
{
	if (!cmd)
		return 0;
	return (!ft_strcmp(cmd, "cd") ||
			!ft_strcmp(cmd, "echo") ||
			!ft_strcmp(cmd, "pwd") ||
			!ft_strcmp(cmd, "exit") ||
			!ft_strcmp(cmd, "env") ||
			!ft_strcmp(cmd, "export") ||
			!ft_strcmp(cmd, "unset"));
}
