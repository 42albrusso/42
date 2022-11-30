/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:54:33 by albrusso          #+#    #+#             */
/*   Updated: 2022/11/14 17:37:14 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_sc
{
	int	len;
}	t_sc;

void	ft_is_c(va_list arg, t_sc *sc);

void	ft_is_d_or_i(va_list arg, t_sc *sc);

void	ft_is_s(va_list arg, t_sc *sc);

void	ft_is_x(va_list arg, t_sc *sc, const char format);

void	ft_putchar(char c, t_sc *sc);

void	ft_putstr(char *str, t_sc *sc);

void	ft_putnbr(long int nbr, t_sc *sc);

int		ft_intlen(int nbr);

int		ft_printf(const char *format, ...);

void	ft_is_p(va_list arg, t_sc *sc);

void	ft_puthex(unsigned int nbr, char *hex, t_sc *sc);

void	ft_putnbru(unsigned int nb, t_sc *sc);

void	ft_is_u(va_list arg, t_sc *sc);

size_t	ft_strlen(const char *s);

char	*ft_itoa(int n);

#endif
