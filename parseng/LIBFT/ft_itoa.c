/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaloulid <jaloulid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 00:59:45 by jaloulid          #+#    #+#             */
/*   Updated: 2024/11/22 06:14:34 by jaloulid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	num_len(int n)
{
	unsigned int	n_len;

	n_len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n_len++;
	while (n)
	{
		n /= 10;
		n_len++;
	}
	return (n_len);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	len;
	long			nb;

	len = num_len(n);
	nb = n;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
		str[0] = '0';
	str[len] = '\0';
	while (nb != 0)
	{
		str[len - 1] = (nb % 10) + '0';
		nb /= 10;
		len--;
	}
	return (str);
}
