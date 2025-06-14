/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoessedr <yoessedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 16:59:55 by yoessedr          #+#    #+#             */
/*   Updated: 2025/06/14 17:08:38 by yoessedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int g_exit_status = 0; 

void ft_exit(char **argv,int ac)
{
    int exit_status;

    exit_status = 0;
    if(ac > 1)
    {
        if(only_digit(argv[1]))
            exit_status = ft_atoi(argv[1]);   
    }
    else
        exit_status = g_exit_status;
    exit(exit_status);
}
