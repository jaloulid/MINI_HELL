/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaloulid <jaloulid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 01:02:40 by jaloulid          #+#    #+#             */
/*   Updated: 2024/11/22 00:20:54 by jaloulid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *t_find, size_t n)
{
	char	*str;
	size_t	t_find_len;

	str = (char *)src;
	if (!*t_find)
		return (str);
	t_find_len = ft_strlen(t_find);
	while (*str && n >= t_find_len)
	{
		if (*str == *t_find)
		{
			if (ft_strncmp(str, t_find, t_find_len) == 0)
				return (str);
		}
		str++;
		n--;
	}
	return (NULL);
}

// int main()
// {
//    printf("%s\n", ft_strnstr("raktema hello arajole", "j" , 20));
// }
