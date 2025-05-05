/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaloulid <jaloulid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 06:55:06 by jaloulid          #+#    #+#             */
/*   Updated: 2025/04/30 01:54:45 by jaloulid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*new_token(char *value, t_token_type type)
{
	t_token	*token;

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
	if (ft_strcmp(s, "|") == 0)
		return (PIPE);
	else if (ft_strcmp(s, "<") == 0)
		return (REDIR_IN);
	else if (ft_strcmp(s, ">") == 0)
		return (REDIR_OUT);
	else if (ft_strcmp(s, ">>") == 0)
		return (REDIR_APPEND);
	else if (ft_strcmp(s, "<<") == 0)
		return (HEREDOC);
	return (WORD);
}

static void	handle_operator(char *line, int *i, t_token **list)
{
	char	op[3];

	op[0] = line[*i];
	op[1] = '\0';
	if ((line[*i] == '<' || line[*i] == '>') && line[*i + 1] == line[*i])
	{
		op[1] = line[++(*i)];
		op[2] = '\0';
	}
	(*i)++;
	add_back(list, new_token(op, get_token_type(op)));
}

static void	handle_word(char *line, int *i, t_token **list)
{
	int		j;
	char	*word;

	j = 0;
	while (line[*i + j] && line[*i + j] != ' ' && line[*i + j] != '|'
		&& line[*i + j] != '<' && line[*i + j] != '>')
		j++;
	word = ft_substr(&line[*i], 0, j);
	add_back(list, new_token(word, WORD));
	free(word);
	*i += j;
}

t_token	*lexer(char *line)
{
	t_token	*list;
	int		i;

	list = NULL;
	i = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (!line[i])
			break ;
		if (line[i] == '|' || line[i] == '<' || line[i] == '>')
			handle_operator(line, &i, &list);
		else
			handle_word(line, &i, &list);
	}
	return (list);
}