/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaloulid <jaloulid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 23:40:07 by jaloulid          #+#    #+#             */
/*   Updated: 2025/05/30 23:40:09 by jaloulid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int parse_redirect_token(t_token **tokens, t_cmd *cmd, t_cmd **cmds)
{
    t_token *token;
    t_redir *redir;

    token = *tokens;
    if (!token->next || token->next->type != WORD)
    {
        printf("minishell: syntax error near unexpected token 'newline'\n");
        free_cmd_list(*cmds);
        return (0);
    }
    redir = new_redir(token->next->value, (t_redir_type)token->type);
    if (!redir)
    {
        printf("minishell: redirection allocation failed\n");
        free_cmd_list(*cmds);
        return(0);
    }
    redir_add_back(&cmd->redirect, redir);
    *tokens = token->next;
    return (1);
}