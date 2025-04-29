/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaloulid <jaloulid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 06:05:49 by jaloulid          #+#    #+#             */
/*   Updated: 2025/04/25 06:53:06 by jaloulid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>

typedef enum e_token_type
{
    WORD,
    PIPE,
    REDIR_IN,
    REDIR_OUT,
    REDIR_APPEND,
    HERDOC        
}   t_token_type;

typedef struct _token
{
    char            *value;
    t_token_type    type;
    struct s_token  *next;
}   t_token;

t_token *new_token(char *value, t_token_type type);

#endif
