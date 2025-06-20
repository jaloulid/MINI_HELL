/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoessedr <yoessedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 16:59:55 by yoessedr          #+#    #+#             */
/*   Updated: 2025/06/19 01:22:07 by yoessedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int g_exit_status = 0;

int ft_exit(char **av, t_node **env)
{
    int exit_status;

    if (av[1] == NULL)
    {
        env_sort(env);
        exit(g_exit_status);
    }
    
    if (only_digit(av[1]) == 0)
    {
        fprintf(stderr, "exit: %s: numeric argument required\n", av[1]);
        exit_status = 255;
    }
    else
    {
        exit_status = atoi(av[1]);
        if (exit_status < 0 || exit_status > 255)
            exit_status = exit_status % 256;
    }

    env_sort(env);
    exit(exit_status);
}
