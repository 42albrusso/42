/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_d_or_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:49:54 by albrusso          #+#    #+#             */
/*   Updated: 2022/11/14 17:33:21 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intlen(int nbr)
{
	int		x;
	char	*c;

	c = ft_itoa(nbr);
	x = ft_strlen(c);
	free(c);
	return (x);
}

void	ft_putnbr(long int nb, t_sc *sc)
{
	if (nb < 0)
	{
		ft_putchar('-', sc);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, sc);
		nb = nb % 10;
	}
	if (nb < 10)
		ft_putchar(nb + 48, sc);
}

void	ft_is_d_or_i(va_list arg, t_sc *sc)
{
	long int	n;

	n = (long int) va_arg(arg, int);
	ft_putnbr(n, sc);
}
