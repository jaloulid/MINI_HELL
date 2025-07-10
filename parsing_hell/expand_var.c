/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaloulid <jaloulid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 23:39:07 by jaloulid          #+#    #+#             */
/*   Updated: 2025/05/30 23:50:27 by jaloulid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *expand_var(char *str, t_node *env, int last_exit)
{
    char    *res;
    char    *tmp;
    int i;

    res = ft_strdup("");
    i = 0;

    while (str[i])
    {
        if (str[i] == '$')
        {
            i++;
            tmp = expand_dollar(str, &i, env, last_exit);
            res = append_str(res, tmp);
            free(tmp);
        }
        else
            res = append_char(res, str[i++]);
    }
    return (res);
}