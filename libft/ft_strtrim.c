/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaloulid <jaloulid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 01:02:57 by jaloulid          #+#    #+#             */
/*   Updated: 2024/11/22 10:14:07 by jaloulid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_char(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*ptr;
	int		i;

	start = 0;
	while (s1[start] && ft_check_char(s1[start], set))
		start++;
	end = ft_strlen((char *)s1);
	while (end > start && ft_check_char(s1[end - 1], set))
		end--;
	ptr = (char *)malloc(sizeof(*ptr) * (end - start + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (start < end)
	{
		ptr[i] = s1[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// int main(void)
// {
//    char str[] = "fatal tigers";
//    char set[] = "f";
//    char *p;
//    p = ft_strtrim(str, set);
//    printf("%s \n", p);