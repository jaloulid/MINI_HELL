/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parseng.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaloulid <jaloulid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 23:39:56 by jaloulid          #+#    #+#             */
/*   Updated: 2025/07/06 21:12:51 by jaloulid         ###   ########.fr       */
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
		// printf("%s\n", cmds->args[5]);	
		// else
		// 	printf("cmds or cmds-> is NULL\n");
		// // if (!cmds)
		// // 	expand_cmds(cmds, env, g_exit_status);
		// printf("%p\n",cmds->args[0]);
		expand_cmds(cmds, env, g_exit_status);
		free_token_list(tokens);
		free_cmd_list(cmds);
		free(line);
	}
	return (0);
}
