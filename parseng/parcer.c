/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaloulid <jaloulid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 23:40:14 by jaloulid          #+#    #+#             */
/*   Updated: 2025/06/02 01:17:25 by jaloulid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd   *parse_tokens(t_token *tokens)
{
    t_cmd   *cmds;
    t_cmd   *current;
    
    cmds = NULL;
    current = NULL;
    while (tokens)
    {
       parse_init_cmd(&current, &cmds);
        if (tokens->type == WORD)
            parse_word_token(&tokens, current);
        else if (is_redirect(tokens))
        {
            if (!parse_redirect_token(&tokens, current, &cmds))
                return NULL;
        }        
        else if (tokens->type == PIPE)
        {
            parse_handle_pipe(&current);
        }
        tokens = tokens->next; 
    }
    return (cmds);
}
