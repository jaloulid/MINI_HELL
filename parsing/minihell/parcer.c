/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaloulid <jaloulid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 23:40:14 by jaloulid          #+#    #+#             */
/*   Updated: 2025/06/20 22:32:12 by jaloulid         ###   ########.fr       */
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
        if (tokens->type == WORD)
        {
            parse_init_cmd(&current, &cmds);
            parse_word_token(&tokens, current); 
        }
        else if (is_redirect(tokens))
        {
            parse_init_cmd(&current, &cmds);
            if (!parse_redirect_token(&tokens, current, &cmds))
            {
                free_cmd_list(cmds);
                return NULL;
            }
        }
        else if (tokens->type == PIPE)
            parse_handle_pipe(&current);
        tokens = tokens->next;
        
    }
    return (cmds);
}
// parse_init_cmd(&current, &cmds);
        //     free_cmd_list(cmds);
        //     return NULL;
        // if (tokens->type == WORD)
        //     parse_word_token(&tokens, current);
        // else if (is_redirect(tokens))
        // {
        //     if (!parse_redirect_token(&tokens, current, &cmds))
        //        {
        //             free_cmd_list(cmds);
        //             return NULL;
        //        } 
        // }     
        // else if (tokens->type == PIPE)
        //     parse_handle_pipe(&current);
            
        // if (tokens)    
        //     tokens = tokens->next; 
