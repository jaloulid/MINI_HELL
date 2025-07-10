/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoessedr <yoessedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 23:39:56 by jaloulid          #+#    #+#             */
/*   Updated: 2025/07/09 09:19:19 by yoessedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int main(int ac, char **av, char **envp)
{
	extern int g_exit_status;
	t_node *env;
	char	*line;
	t_token	*tokens;
	t_cmd	*cmds;
	
	(void)ac;
	(void)av;
	env = env_init(envp);
	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
			break ;
		add_history(line);
		tokens = lexer(line);
		cmds = parse_tokens(tokens);
		if(pipe_number(cmds) == 1 && cmds->redirect == NULL)
			g_exit_status = exec_cmd(cmds->args, &env);
		else
			g_exit_status = exec_pipes(cmds, &env);
		if (g_exit_status == -1)
		{
			free_token_list(tokens);
			free_cmd_list(cmds);
			free(line);
			free(env);
			return (1);
		}
		expand_cmds(cmds, &env, g_exit_status);
		free_token_list(tokens);
		free_cmd_list(cmds);
		free(line);
	}
	return (0);
}
