#include "minishell.h"
#include <readline/readline.h>
#include <stdio.h>

void	print_tokens(t_token *list)
{
	while (list)
	{
		printf("Token: %-12s | Type: %d\n", list->value, list->type);
		list = list->next;
	}
}

int	main(void)
{
	char	*line;
	t_token	*tokens;

	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
			break ;
		tokens = lexer(line);
		print_tokens(tokens);
	}
}