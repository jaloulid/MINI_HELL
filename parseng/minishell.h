/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaloulid <jaloulid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 06:05:49 by jaloulid          #+#    #+#             */
/*   Updated: 2025/05/08 20:39:10 by jaloulid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <string.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef enum e_token_type
{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	HEREDOC
}	t_token_type;

typedef struct s_token
{
	char			*value;
	t_token_type	type;
	struct s_token	*next;
}	t_token;

t_token	*lexer(char *line);
t_token *new_token(char *value, t_token_type type);
void	add_back(t_token **list, t_token *new);
t_token_type	get_token_type(char *s);
int get_word_len(char *line);
void    handle_word(char *line, int *i, t_token **list);
void    free_token_list(t_token *list);
void    handle_operator(char *line, int *i, t_token **list);

#endif
