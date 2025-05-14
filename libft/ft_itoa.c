/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoessedr <yoessedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 00:36:17 by yoessedr          #+#    #+#             */
/*   Updated: 2024/11/09 17:41:19 by yoessedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_number_of_div(unsigned int n, int base)
{
	unsigned int	num;

	if (base < 2)
		return (-1);
	if (n == 0)
		return (1);
	num = 0;
	if ((int)n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= base;
		num++;
	}
	return (num);
}

char	*ft_itoa(int n)
{
	char			*integer;
	unsigned int	num;
	int				len;

	num = n;
	if (n < 0)
		num = -n;
	len = ft_number_of_div(num, 10);
	if (n < 0)
		len++;
	integer = malloc(len + 1);
	if (!integer)
		return (NULL);
	integer[len] = '\0';
	if (n == 0)
		integer[0] = '0';
	if (n < 0)
		integer[0] = '-';
	while (num)
	{
		integer[--len] = num % 10 + '0';
		num /= 10;
	}
	return (integer);
}
