/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaloulid <jaloulid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:35:14 by jaloulid          #+#    #+#             */
/*   Updated: 2024/11/21 23:41:29 by jaloulid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	if (s && start < ft_strlen(s))
	{
		if (start + len < ft_strlen(s))
			tmp = malloc(sizeof(char) * len + 1);
		else
			tmp = malloc(sizeof(char) * (ft_strlen(s) - start) + 1);
		if (!tmp)
			return (NULL);
		while (start + i < ft_strlen(s) && i < len)
		{
			tmp[i] = s[i + start];
			i++;
		}
		tmp[i] = 0;
	}
	else
		return (ft_strdup(""));
	return (tmp);
}
// #include <string.h>

// int	main(void)
// {
// 	char	str[] = "zz";
// 	char *file = ft_substr(str, 10, 1);
// 	printf("%s\n", file);
// 	return (0);
// }
