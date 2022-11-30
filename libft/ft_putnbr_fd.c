/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:04:07 by albrusso          #+#    #+#             */
/*   Updated: 2022/11/11 15:47:59 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnum(int a, int fd)
{
	a += 48;
	write (fd, &a, 1);
}

void	ft_stampa(int i, int v[], int fd)
{
	i--;
	while (i >= 0)
	{
		ft_putnum(v[i], fd);
		i--;
	}
}

void	ft_controllo(int nb, int v[], int i, int fd)
{
	if (nb == -2147483648)
	{
		write (fd, "-2", 2);
		write (fd, "147483648", 9);
	}
	else if (nb == 0)
		ft_putnum(0, fd);
	else if (nb < 0 && nb != -2147483648)
	{
		nb = nb * -1;
		write (fd, "-", 1);
	}
	while (nb > 0)
	{
		v[i] = nb % 10;
		nb = nb / 10;
		i++;
	}
	ft_stampa(i, v, fd);
}

void	ft_putnbr_fd(int nb, int fd)
{
	int	i;
	int	v[9];

	i = 0;
	ft_controllo(nb, v, i, fd);
}
