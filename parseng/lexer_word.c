/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaloulid <jaloulid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:50:30 by jaloulid          #+#    #+#             */
/*   Updated: 2025/05/08 20:38:09 by jaloulid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    handle_operator(char *line, int *i, t_token **list)
{
    char op[3];
    int j;

    j = 0;
    op[j++] = line[*i];
    if ((line[*i] == '>' || line[*i] == '<') && line[*i + 1] == line[*i])
        op[j++] = line[++(*i)];
    op[j] = '\0';
    (*i)++;
    add_back(list, new_token(op, get_token_type(op)));
}
static int  skip_quotes(char *line, int i)
{
    char    q;
    
    q = line[i++];
    while (line[i] && line[i] != q)
        i++;
    if (line[i] == q)
        i++;
    return (i);
}
int get_word_len(char *line)
{
    int i;

    i = 0;
    while (line[i] && line[i] != ' ' && line[i] != '|' && line[i] != '<' && line[i] != '>')
    {
        if (line[i] == '\'' || line[i] == '"')
            i = skip_quotes(line, i);
        else
            i++;
    }
    return (i);
}
void    handle_word(char *line, int *i, t_token **list)
{
    int len;
    char    *word;

    len = get_word_len(&line[*i]);
    word = ft_substr(line, *i, len);
    add_back(list, new_token(word, WORD));
    free(word);
    *i += len;
}
