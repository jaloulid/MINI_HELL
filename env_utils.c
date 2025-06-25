/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaloulid <jaloulid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 23:39:37 by jaloulid          #+#    #+#             */
/*   Updated: 2025/06/02 00:40:03 by jaloulid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// to do env new 
// args :(key, value)

// alloc(sizeof(t_node));
//head->key = key;
//head->value = value;
// next = NULL;
// return ( node )

#include "minishell.h"

t_node  *env_add_new(char *key, char *value)
{
	t_node *new_node;

	new_node = malloc(sizeof(t_node));
	if(!new_node)
		return(NULL);
	new_node->key = key;
	new_node->value = value;
	new_node->next = NULL;
	return(new_node);
}

t_node	*env_add_back(t_node *env, t_node *new)
{
	t_node *tmp;

	tmp = env;
	if (env == NULL)
		return (env);	
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return(env);
}




// args (key, value) 
// while  3la env
// fach katl9a key
// updati value b value jdida
// sinon katzido f lekher 



    // char * key = ft_substr(*env, 0, len);
    // char *value =  ft_strdup(found + 1);
  //  t_node = env_new(key, value) ;
  // env_add_back(**head, env_new(key, value))


t_node *env_init(char **env)
{
   t_node *head = NULL;
   t_node *new_node;
   char *found;
   char *key;
   char *value;
   int len ;
   
   while(*env)
   {
    found = ft_strchr(*env, '=');
    if (!found || **env == '=' || found == *env)
    {
      env++;
      continue ;
    }
    len = found - *env;
    key = ft_substr(*env, 0, len);
    value = ft_strdup(found + 1);
    //printf("ENV_INIT : key = %s | value = %s\n", key, value);
	  new_node = env_add_new(key, value);
    head = env_add_back(head, new_node);
    env++;
  }
   return (head);
}

// export katziid lik wahd env felkher 

// export variable="youssef" -===>  key = variable ,  value = "youssef"
// env_add_back(head, env_new(key, value))

// env

// ya sahbi hadchy kane 3endek m5erbe9 yalah 9adiite hed lenvirement lmhm hana gadiite hedchy hada kamelle w ana saliite wa 3jeeebni 
// acy youssef yalahe feke rassek