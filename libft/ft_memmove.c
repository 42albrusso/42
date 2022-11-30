/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:15:36 by albrusso          #+#    #+#             */
/*   Updated: 2022/11/11 15:47:55 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_norm1(char *cdest, char *csrc, char c, size_t i)
{
	while (i > 0)
	{
		i--;
		c = csrc[i];
		cdest[i] = c;
	}
}

void	ft_norm2(char *cdest, char *csrc, size_t n, size_t i)
{
	char	c;

	while (i < n)
	{
		c = csrc[i];
		cdest[i] = c;
		i++;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*cdest;
	char		*csrc;
	size_t		i;
	char		c;

	i = 0;
	c = ' ';
	if (!dest && !src)
		return (NULL);
	else
	{
		cdest = (char *)dest;
		csrc = (char *)src;
		if (cdest > csrc)
		{
			i = n;
			ft_norm1(cdest, csrc, c, i);
		}
		else
			ft_norm2(cdest, csrc, n, i);
	}
	return (dest);
}
