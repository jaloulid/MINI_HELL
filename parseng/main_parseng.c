/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaloulid <jaloulid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 23:39:56 by jaloulid          #+#    #+#             */
/*   Updated: 2025/05/31 01:53:54 by jaloulid         ###   ########.fr       */
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
		expand_cmds(cmds, env, g_exit_status);
		//print_cmds(cmds);

		free_token_list(tokens);
		free_cmd_list(cmds);
		free(line);
	}
	return (0);
}
