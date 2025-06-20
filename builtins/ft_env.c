#include "minishell.h"

int ft_env(t_node *env)
{
    t_node *current = env;

    if (!current)
    {
        return 0;
    }

    while (current)
    {
        if (current->key && current->value)
        {
            printf("%s=%s\n", current->key, current->value);
        }
        current = current->next;
    }
    
    return 0;
}