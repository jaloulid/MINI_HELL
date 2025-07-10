/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaloulid <jaloulid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:41:03 by jaloulid          #+#    #+#             */
/*   Updated: 2025/05/23 19:27:27 by jaloulid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token *new_token(char *value, t_token_type type)
{
    t_token *token;

    token = malloc(sizeof(t_token));
    if (!token)
        return (NULL);
    token->value = ft_strdup(value);
    token->type = type;
    token->next = NULL;
    return (token);    
}
void	add_back(t_token **list, t_token *new)
{
	t_token	*tmp;

	if (!*list)
	{
		*list = new;
		return ;
	}
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
t_token_type	get_token_type(char *s)
{
	if (ft_strncmp(s, "|", 2) == 0)
		return (PIPE);
	else if (ft_strncmp(s, "<", 2) == 0)
		return (REDIR_IN);
	else if (ft_strncmp(s, ">", 2) == 0)
		return (REDIR_OUT);
	else if (ft_strncmp(s, ">>", 3) == 0)
		return (REDIR_APPEND);
	else if (ft_strncmp(s, "<<", 3) == 0)
		return (HEREDOC);
	return (WORD);
}
