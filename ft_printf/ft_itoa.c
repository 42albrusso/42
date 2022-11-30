/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:05:49 by albrusso          #+#    #+#             */
/*   Updated: 2022/11/14 15:59:17 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ldnum(char *str)
{
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}

char	*ft_putstrs(char *str, int c, int n, int s)
{
	str[c] = '\0';
	while (c > 0)
	{
		c--;
		str[c] = (n % 10) + 48;
		n = n / 10;
	}
	if (s == -1)
		str[0] = '-';
	return (str);
}

int	ft_sizestr(int n, int c)
{
	int	x;

	x = n;
	if (x < 0 && n != -2147483648)
	{
		x = x * (-1);
		n = n * (-1);
		c++;
	}
	while (x > 0)
	{
		x = x / 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	int		sign;
	char	*ptr;
	int		count;

	count = 0;
	sign = 0;
	if (n == -2147483648)
		count = 11;
	if (n == 0)
		count = 1;
	count = ft_sizestr(n, count);
	if (n < 0)
	{
		sign = -1;
		n = n * (-1);
	}
	ptr = (char *)malloc(count + 1);
	if (!ptr)
		return (NULL);
	if (n == -2147483648)
		return (ft_ldnum(ptr));
	ptr = ft_putstrs(ptr, count, n, sign);
	return (ptr);
}
