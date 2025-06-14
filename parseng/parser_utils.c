/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaloulid <jaloulid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:06:36 by jaloulid          #+#    #+#             */
/*   Updated: 2025/05/21 19:40:12 by jaloulid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redir *new_redir(char *file, t_redir_type type)
{
    t_redir *redir;

    redir = malloc(sizeof(t_redir));
    if (!redir)
        return NULL;
    redir->file = ft_strdup(file);
    redir->type = type;
    redir->next = NULL;
    return (redir);    
}
void    redir_add_back(t_redir **lst, t_redir *new)
{
    t_redir *tmp;
    
    if (!*lst)
    {
        *lst = new;
        return;
    }
    tmp = *lst;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;    
}
