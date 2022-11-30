/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:58:25 by albrusso          #+#    #+#             */
/*   Updated: 2022/11/11 15:47:53 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*cstr1;
	unsigned char	*cstr2;
	size_t			i;

	i = 0;
	cstr1 = (unsigned char *)str1;
	cstr2 = (unsigned char *)str2;
	while (i < n)
	{
		if (cstr1[i] != cstr2[i])
			return (cstr1[i] - cstr2[i]);
		else
			i++;
	}
	return (0);
}
