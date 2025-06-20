/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoessedr <yoessedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 00:01:28 by yoessedr          #+#    #+#             */
/*   Updated: 2025/06/19 00:07:41 by yoessedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_env(t_node *env)
{
    t_node *current = env;

    while (current)
    {
        if (current->key && current->value)
            printf("%s=%s\n", current->key, current->value);
        current = current->next;
    }
    return 0;
}

