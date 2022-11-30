/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:05:50 by albrusso          #+#    #+#             */
/*   Updated: 2022/11/11 15:48:08 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *str, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	dlen;
	size_t	slen;

	dlen = ft_strlen(dest);
	slen = ft_strlen(str);
	j = 0;
	i = ft_strlen(dest);
	if (dlen < n - 1 && n > 0)
	{
		while (str[j] && dlen + j < n - 1)
		{
			dest[i] = str[j];
			j++;
			i++;
		}
		dest[i] = '\0';
	}
	if (dlen >= n)
		dlen = n;
	return (dlen + slen);
}
