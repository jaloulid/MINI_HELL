#include "minishell.h"

int ft_search(char *str, t_node **env)
{
    while(*env && ft_strcmp((*env)->key, str) != 0)
    {
        *env = (*env)->next;
    }
    if((*env)->next == NULL)
		return (0);
	else
		return(1);

}

int    env_sort(t_node **env)
{
    t_node  *copy;
    t_node *tmp;
    copy = *env;

    while(*env)
    {
        while(copy)
        {
            if(ft_strcmp(copy->key, copy->next->key))
            {
                tmp->key = copy->next->key;
                copy->next->key = copy->key;
                copy->key = tmp->key;
            }
            copy = copy->next;
        }
        (*env) = (*env)->next;
        copy = *env;
    }
    return(0);
}

int ft_strcmp(char *src, char *dest)
{
    int i;

    i = 0;
    while(src[i] && dest[i] && (src[i] == dest[i]))
        i++;
    return(src[i] - dest[i]);
}

t_node  *return_address(char *str, t_node **env)
{
    t_node *looper;

    looper = (*env);
    while(looper && looper->key != str)
        looper = looper->next;
    return(looper);
}
int only_digit(char *str)
{
	int i;

	i = 0;
	while(str[i] && (str[i] >= '0' && str[i] <= '9'))
		i++;
	if(str[i] == '\0')
		return(1);
	else
		return(0);
}
