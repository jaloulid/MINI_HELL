/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaloulid <jaloulid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 23:40:07 by jaloulid          #+#    #+#             */
/*   Updated: 2025/07/13 04:33:26 by jaloulid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"

// int parse_redirect_token(t_token **tokens, t_cmd *cmd, t_cmd **cmds)
// {
//     t_token *token;
//     t_redir *redir;

//     token = *tokens;
//     if (!token->next || token->next->type != WORD)
//     {
//         printf("minishell: syntax error near unexpected token 'newline'\n");
//         free_cmd_list(*cmds);
//         return (0);
//     }
//     redir = new_redir(token->next->value, (t_redir_type)token->type);
//     if (!redir)
//     {
//         printf("minishell: redirection allocation failed\n");
//         free_cmd_list(*cmds);
//         return(0);
//     }

//     redir_add_back(&cmd->redirect, redir);
//     *tokens = token->next;
//     return (1);
// }
#include "minishell.h"

static t_redir_type get_redir_type(t_token_type token_type) 
{ 
    if (token_type == REDIR_IN)
     return (R_IN); 
     else if (token_type == REDIR_OUT)
      return (R_OUT);
       else if (token_type == REDIR_APPEND)
        return (R_APPEND);
         else if (token_type == HEREDOC) 
         return (R_HEREDOC);
          return (-1);
 }

t_redir *build_redirection(t_token *token) 
{ 
    t_redir *redir;

if (!token || !token->next || !token->next->value)
	return (NULL);

redir = malloc(sizeof(t_redir));
if (!redir)
	return (NULL);

redir->file = ft_strdup(token->next->value);
if (!redir->file)
	return (free(redir), NULL);

redir->type = get_redir_type(token->type);
redir->next = NULL;
return (redir);

}

int parse_redirect_token(t_token **tokens, t_cmd *cmd)
{ 
    t_redir *redir;

if (!tokens || !*tokens)
	return (0);
redir = build_redirection(*tokens);
if (!redir)
	return (0);
redir_add_back(&cmd->redirect, redir);
*tokens = (*tokens)->next;
*tokens = (*tokens)->next;
return (1);

}