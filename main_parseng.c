/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parseng.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoessedr <yoessedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 23:39:56 by jaloulid          #+#    #+#             */
/*   Updated: 2025/06/21 00:45:34 by yoessedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

// void	print_tokens(t_token *list)
// {
// 	while (list)
// 	{
// 		printf("Token: %-12s | Type: %d\n", list->value, list->type);
// 		list = list->next;
// 	}
// }
// printf("%s\n", line);
// print_tokens(tokens);
//print_cmds(cmds);

// int main(int ac, char **av, char **envp)
// {
// 	extern int g_exit_status;
// 	t_node *env;
// 	char	*line;
// 	t_token	*tokens;
// 	t_cmd	*cmds;
	
// 	(void)ac;
// 	(void)av;
// 	env = env_init(envp);
// 	// show the envirement
// 	t_node *tmp = env;
// 	while (tmp)
// 	{
// 		printf("key: %s | value; %\n", tmp->key, tmp->value);
// 			tmp = tmp->next;
// 	}
// 	// get specific variable
// 	char *test = get_env_value(env, "USER");
// 	if (test)
// 		printf("TEST: USER = %s\n", test);
// 	else
// 		printf("TEST: USER not found!\n");
// 	while (1)
// 	{
// 		line = readline("minishell$ ");
// 		if (!line)
// 			break ;
// 		tokens = lexer(line);
// 		cmds = parse_tokens(tokens);
// 		expand_cmds(cmds, env, g_exit_status);
// 		free_token_list(tokens);
// 		free_cmd_list(cmds);
// 		free(line);
// 	}
// 	return (0);
// }

// show the envirement
	// t_node *tmp = env;
	// while (tmp)
	// {
	// 	printf("key: %s | value; %s\n", tmp->key, tmp->value);
	// 		tmp = tmp->next;
	// }
	// get specific variable
	// char *test = get_env_value(env, "USER");

	// if (test)
	// 	printf("TEST: USER = %s\n", test);
	// else
	// 	printf("TEST: USER not found\n");
	//  print_cmds(cmds);
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
		tokens = lexer(line);
		cmds = parse_tokens(tokens);
		if(pipe_number(cmds) == 1)
			g_exit_status = exec_cmd(cmds->args, &env);
		else
			g_exit_status = exec_pipes(cmds, &env);
		if (g_exit_status == -1)
		{
			fprintf(stderr, "Execution failed\n");
			free_token_list(tokens);
			free_cmd_list(cmds);
			free(line);
			continue;
		}
		expand_cmds(cmds, &env, g_exit_status);
		free_token_list(tokens);
		free_cmd_list(cmds);
		free(line);
	}
	return (0);
}
