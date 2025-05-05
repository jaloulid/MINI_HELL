/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaloulid <jaloulid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 00:59:52 by jaloulid          #+#    #+#             */
/*   Updated: 2024/11/22 09:56:15 by jaloulid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == ((unsigned char)c))
			return (&(((unsigned char *)s)[i]));
		i++;
	}
	return (NULL);
}
// int main()
// {
// 	char ss[] = "..........vodka.....";

// 	printf("%s", (char *)ft_memchr(ss, 'v', sizeof(ss)));
// }
