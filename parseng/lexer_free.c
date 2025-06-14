/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaloulid <jaloulid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:02:41 by jaloulid          #+#    #+#             */
/*   Updated: 2025/05/08 20:20:43 by jaloulid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    free_token_list(t_token *list)
{
    t_token *tmp;
    
    while (list)
    {
        tmp = list->next;
        free(list->value);
        free(list);
        list = tmp;
    }
}