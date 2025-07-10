/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoessedr <yoessedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 00:17:31 by jaloulid          #+#    #+#             */
/*   Updated: 2025/07/10 18:46:35 by yoessedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    expand_cmds(t_cmd *cmds, t_node *env, int status)
{
    int i;
    t_redir *r;
    
    if (!cmds)
        return;
    while (cmds)
    {
        i = 0;
        while (cmds->args && cmds->args[i])
        {
            char    *tmp;
            tmp = expand_var(cmds->args[i], env, status);
            free(cmds->args[i]);
            cmds->args[i++] = tmp;
        }
        r = cmds->redirect;
        while (r)
        {
            char *tmp1;
            tmp1 = expand_var(r->file, env, status);
            free(r->file);
            r->file = tmp1;
            r = r->next;
        }
        cmds = cmds->next;
    }
}
