/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaloulid <jaloulid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 00:59:09 by jaloulid          #+#    #+#             */
/*   Updated: 2024/11/22 10:27:15 by jaloulid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*rs;

	if (count && size > SIZE_MAX / count)
		return (0);
	rs = malloc(count * size);
	if (!rs)
		return (NULL);
	ft_bzero(rs, count * size);
	return (rs);
}
