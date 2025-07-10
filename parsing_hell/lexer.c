/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaloulid <jaloulid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 06:55:06 by jaloulid          #+#    #+#             */
/*   Updated: 2025/06/02 23:36:34 by jaloulid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*lexer(char *line)
{
	t_token	*list;
	int		i;
	int		len;
	
	list = NULL;
	i = 0;
	len = get_word_len(line);
	if (len == -1)
	{
		printf("minishell: syntax error: unclosed quote\n");
		return (NULL);
	}
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
