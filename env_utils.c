#include "minishell.h"

// to do env new 
// args :(key, value)

// alloc(sizeof(t_node));
//head->key = key;
//head->value = value;
// next = NULL;
 // return ( node )


t_node  *env_add_new(char *key, char *value)
{
	t_node *new_node;

	new_node = malloc(sizeof(t_node));
	if(!new_node)
		return(NULL);
	new_node->key = ft_strdup(key);
	new_node->value = ft_strdup(value);
	new_node->next = NULL;
	return(new_node);
}

void	env_add_back(t_node **env, t_node *new)
{
	t_node *tmp;
    if (!env || !new)
		return;
	tmp = *env;
	if (*env == NULL)
	{
		*env = new;
        return;
	}	
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}




// args (key, value) 
// while  3la env
// fach katl9a key
// updati value b value jdida
// sinon katzido f lekher 



t_node *env_init(char **env)
{
   t_node *head = NULL;
   t_node *new_node;
   //t_node *new_node = NULL;
   char *found;
   char *key;
   char *value;
   int len = 0;
    int i = 0;
   
   new_node = head;
  
   while(*env)
   {
    
    found = ft_strchr(*env, '=');
    len = found - *env;
    key = ft_substr(*env, 0, len);
    value = ft_strdup(found + 1);

	new_node = env_add_new(key, value);


    // char * key = ft_substr(*env, 0, len);
    // char *value =  ft_strdup(found + 1);
  //  t_node = env_new(key, value) ;
  // env_add_back(**head, env_new(key, value))


    // if((*env + 1))
    env_add_back(&head, new_node);
    env++;
}
   return head;
}




// export katziid lik wahd env felkher 

// export variable="youssef" -===>  key = variable ,  value = "youssef"
// env_add_back(head, env_new(key, value))

// env
