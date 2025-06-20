/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoessedr <yoessedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 22:27:53 by yoessedr          #+#    #+#             */
/*   Updated: 2025/06/21 00:00:10 by yoessedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_search_env(char *str, t_node *env)
{
    while (env)
    {
        if (ft_strcmp(env->key, str) == 0)
            return (1);
        env = env->next;
    }
    return (0);
}

int env_sort(t_node **env)
{
    int swapped = 1;
    t_node *ptr;

    if (!env || !(*env))
        return 0;

    while (swapped)
    {
        swapped = 0;
        ptr = *env;

        while (ptr && ptr->next)
        {
            if (ft_strcmp(ptr->key, ptr->next->key) > 0)
            {
                swap_env_nodes(ptr, ptr->next);
                swapped = 1;
            }
            ptr = ptr->next;
        }
    }
    return 1;
}

void swap_env_nodes(t_node *a, t_node *b)
{
    char *tmp_key = a->key;
    char *tmp_val = a->value;

    a->key = b->key;
    a->value = b->value;

    b->key = tmp_key;
    b->value = tmp_val;
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
