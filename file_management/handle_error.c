/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoessedr <yoessedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 06:27:27 by yoessedr          #+#    #+#             */
/*   Updated: 2025/07/09 10:31:40 by yoessedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int print_error(char *prefix, char *filename)
{
    if (prefix)
        fprintf(stderr, "%s: ", prefix);
    if (filename)
        fprintf(stderr, "%s: ", filename);
    perror("Error");
    return (1);
}
int handle_file_error(char *filename, int error_code)
{
    if (error_code == ENOENT)
        return print_error("minishell", filename);
    else if (error_code == EACCES)
        return print_error("Permission denied", filename);
    else
        return print_error("Unknown error", filename);
}