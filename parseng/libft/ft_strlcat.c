/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaloulid <jaloulid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 01:01:57 by jaloulid          #+#    #+#             */
/*   Updated: 2024/11/22 10:26:34 by jaloulid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dstlen;
	size_t	srclen;

	if (!dst && dstsize == 0)
		return (ft_strlen(src));
	dstlen = ft_strlen((char *)dst);
	srclen = ft_strlen((char *)src);
	j = 0;
	i = dstlen;
	if (dstsize == 0 || dstsize <= dstlen)
		return (dstsize + srclen);
	while (src[j] != '\0' && j < dstsize - dstlen - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dstlen + srclen);
}
