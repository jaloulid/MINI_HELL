/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoessedr <yoessedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:13:51 by yoessedr          #+#    #+#             */
/*   Updated: 2024/11/13 17:25:30 by yoessedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*rex;
	size_t	com;

	if (size != 0 && count > (size_t) - 1 / size)
		return (NULL);
	com = size * count;
	rex = malloc(com);
	if (!rex)
		return (NULL);
	if (com == 0)
		com = 1;
	ft_memset(rex, 0, com);
	return (rex);
}
