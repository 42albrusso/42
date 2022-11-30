/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:48:45 by albrusso          #+#    #+#             */
/*   Updated: 2022/11/14 17:25:14 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, t_sc *sc)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], sc);
		i++;
	}
}

void	ft_is_s(va_list arg, t_sc *sc)
{
	char	*s;

	s = va_arg(arg, char *);
	if (!s)
		sc->len += write (1, "(null)", 6);
	else
		ft_putstr(s, sc);
}
