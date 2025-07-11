/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoessedr <yoessedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 23:40:14 by jaloulid          #+#    #+#             */
/*   Updated: 2025/07/11 15:02:22 by yoessedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int parse_one_token(t_token *tokens, t_cmd **current, t_cmd **cmds)
{
    if (tokens->type == WORD)
        {
            parse_init_cmd(current, cmds);
            parse_word_token(&tokens, *current);
            return (1);
        }
    else if (is_redirect(tokens))
        {
            parse_init_cmd(current, cmds);
            if (!parse_redirect_token(&tokens, *current, cmds))
                return (0);
            return (1);
        }
    else if (tokens->type == PIPE)
        {
            parse_handle_pipe(current);
                return (1);
        }
        return (1);      
}

t_cmd   *parse_tokens(t_token *tokens)
{
    t_cmd *cmds;
    t_cmd *current;

    cmds = NULL;
    current = NULL;
    
    if (check_pipe_syntax(tokens))
        return NULL;
    while (tokens)
    {
        if (!parse_one_token(tokens, &current, &cmds))
            {
                free_cmd_list(cmds);
                return NULL;
            }
        tokens = tokens->next;
    }
    return(cmds);
}
// t_cmd   *parse_tokens(t_token *tokens)
// {
//     t_cmd   *cmds;
//     t_cmd   *current;
    
//     cmds = NULL;
//     current = NULL;

   
//     while (tokens)
//     {
//         if (tokens->type == WORD)
//         {
//             parse_init_cmd(&current, &cmds);
//             parse_word_token(&tokens, current); 
//         }
//         else if (is_redirect(tokens))
//         {
//             parse_init_cmd(&current, &cmds);
//             if (!parse_redirect_token(&tokens, current, &cmds))
//             {
//                 free_cmd_list(cmds);
//                 return NULL;
//             }
//         }
//         else if (tokens->type == PIPE)
//             parse_handle_pipe(&current);
//         tokens = tokens->next;
//     }
//     return (cmds);
// }
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
