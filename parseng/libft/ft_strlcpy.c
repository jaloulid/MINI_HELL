/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaloulid <jaloulid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 01:02:07 by jaloulid          #+#    #+#             */
/*   Updated: 2024/11/22 00:29:53 by jaloulid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = ft_strlen(src);
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0' ;
	}
	return (res);
}

// int main()
// {
// 	char src[]= "fatal tigers";
// 	char dest[5]= "";
// 	printf("%zu\n", ft_strlcpy(dest, src, 5));
// 	printf("%s\n%s\n", dest, src);	
// }
