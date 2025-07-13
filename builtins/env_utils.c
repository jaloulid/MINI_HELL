/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoessedr <yoessedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 22:27:37 by yoessedr          #+#    #+#             */
/*   Updated: 2025/06/22 07:06:10 by yoessedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
   
   new_node = head;
   while(*env)
   {
    
    found = ft_strchr(*env, '=');
    len = found - *env;
    key = ft_substr(*env, 0, len);
    value = ft_strdup(found + 1);
	new_node = env_add_new(key, value);
    // if((*env + 1))
    env_add_back(&head, new_node);
    env++;
}
   return head;
}

char **env_list_to_array(t_node **env)
{
    int count = 0;
    t_node *tmp = (*env);

    while (tmp)
    {
        count++;
        tmp = tmp->next;
    }
    char **envp = malloc(sizeof(char *) * (count + 1));
    if (!envp)
        return NULL;
    tmp = (*env);
    int i = 0;
    while (tmp)
    {
        int len = ft_strlen(tmp->key) + ft_strlen(tmp->value) + 2;
        envp[i] = malloc(sizeof(char) * len);
        if (!envp[i])
            return NULL;
        ft_strlcpy(envp[i], tmp->key, len);
        ft_strlcat(envp[i], "=", len);
        ft_strlcat(envp[i], tmp->value, len);

        tmp = tmp->next;
        i++;
    }
    envp[i] = NULL;
    return envp;
}

