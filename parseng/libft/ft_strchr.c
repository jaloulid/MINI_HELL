/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaloulid <jaloulid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 01:01:26 by jaloulid          #+#    #+#             */
/*   Updated: 2024/11/22 10:11:51 by jaloulid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	cfound;

	i = 0;
	cfound = 0;
	while (s[i])
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
		{
			cfound = 1;
			break ;
		}
		else
			i++;
	}
	if (cfound == 0 && (unsigned char)c != 0)
		return (NULL);
	return ((char *)&(((unsigned char *)s)[i]));
}

/*int main()
{
	char ss[] = "rake tema";
	printf("%s", ft_strchr(ss, 97));
}*/
