#include "minishell.h"

void	print_cmds(t_cmd *cmds)
{
	int		i;
	int		j;
	t_redir	*r;

	printf("----- COMMANDS -----\n");
	i = 0;
	while (cmds)
	{
		printf("cmd[%d]:\n", i++);
		j = 0;
		while (cmds->args && cmds->args[j])
		{
			printf("  arg[%d] = %s\n", j, cmds->args[j]);
			j++;
		}
		r = cmds->redirect;
		while (r)
		{
			printf("  redir type = %d | file = %s\n", r->type, r->file);
			r = r->next;
		}
		cmds = cmds->next;
	}
}

void	print_tokens(t_token *list)
{
	printf("----- TOKENS -----\n");
	while (list)
	{
		printf("value: %-12s | type: %d\n", list->value, list->type);
		list = list->next;
	}
}