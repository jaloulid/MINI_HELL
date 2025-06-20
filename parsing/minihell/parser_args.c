/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaloulid <jaloulid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 22:45:40 by jaloulid          #+#    #+#             */
/*   Updated: 2025/06/20 16:50:28 by jaloulid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    collect_arg(t_cmd *cmd, char *value)
{
    int i ;
    char **new_args;

    if (!cmd || !value)
     return;
    
    i = 0;
    
    while (cmd->args && cmd->args[i])
        i++;
    new_args = malloc(sizeof(char *) * (i + 2));
    if (!new_args)
        return;
    i = 0;
    while (cmd->args && cmd ->args[i])
    {
        new_args[i] = cmd->args[i];
        i++;
    }
    new_args[i++] = ft_strdup(value);
    new_args[i] = NULL;
    free(cmd->args);
    cmd->args = new_args;
}
void    parse_word_token(t_token **tokens, t_cmd *cmd)
{
    if ((*tokens)->type == WORD && cmd)
        
        collect_arg(cmd, (*tokens)->value);
}