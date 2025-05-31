/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaloulid <jaloulid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 23:40:26 by jaloulid          #+#    #+#             */
/*   Updated: 2025/05/30 23:40:29 by jaloulid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    parse_init_cmd(t_cmd **current, t_cmd **cmds)
{
    if (!current)
    {
        *current = new_cmd();
        if (!*current)
            return ;
        cmd_add_back(cmds, *current);
    }
}
void    parse_handle_pipe(t_cmd **current)
{
    *current = NULL;
}