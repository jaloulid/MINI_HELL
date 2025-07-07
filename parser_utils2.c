/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaloulid <jaloulid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 23:40:26 by jaloulid          #+#    #+#             */
/*   Updated: 2025/07/06 20:47:12 by jaloulid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    parse_init_cmd(t_cmd **current, t_cmd **cmds)
{
    if (!*current)
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
int check_pipe_syntax(t_token *tokens)
{
    if (tokens && tokens->type == PIPE)
        {
            printf("minishell: syntax error near unexpected token '|'\n");
                return (1);
        }
        return (0);
}