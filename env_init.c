#include "minishell.h"

t_node *env_init(char **env)
{
   t_node *head;
   t_node *new_node;
   char *found;
   int len = 0;

   head = malloc(sizeof(t_node));
   head->key = NULL;
   head->value = NULL;
   head->next = NULL;
   new_node = head;
   while(*env)
   {
    found = ft_strchr(*env, '=');
    len = found - *env;
    new_node->key = ft_substr(*env, 0, len);
    new_node->value = ft_strdup(found + 1);
    if (*(env + 1))
    {
        new_node->next = malloc(sizeof(t_node));
        new_node = new_node->next;
        new_node->key = NULL;
        new_node->value = NULL;
        new_node->next = NULL;
    }
    env++;
}
   return head;
}
