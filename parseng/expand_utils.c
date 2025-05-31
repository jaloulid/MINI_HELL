/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaloulid <jaloulid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 00:11:45 by jaloulid          #+#    #+#             */
/*   Updated: 2025/05/31 00:15:34 by jaloulid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *append_char(char *base, char c)
{
    char tmp[2] = {c, '\0'};
    return (append_str(base, tmp));
}
char    *append_str(char *base, char *add)
{
    char    *tmp;

    if (!add)
        return (base);
    tmp = base;
    base = ft_strjoin(base, add);
    free (tmp);
    return (base);
}