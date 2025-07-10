/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaloulid <jaloulid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:27:02 by jaloulid          #+#    #+#             */
/*   Updated: 2025/05/22 19:37:36 by jaloulid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    free_cmd_list(t_cmd *cmd)
{
    t_cmd   *tmp;
    t_redir *r_tmp;
    
    while (cmd)
    {
        int i = 0;
        tmp = cmd->next;
        while (cmd->args && cmd->args[i])
            free(cmd->args[i++]);
        free(cmd->args);
        while (cmd->redirect)
        {
            r_tmp = cmd->redirect->next;
            free(cmd->redirect->file);
            free(cmd->redirect);
            cmd->redirect = r_tmp;
        }
        free(cmd);
        cmd = tmp;
    }
}