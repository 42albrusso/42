/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:03:36 by albrusso          #+#    #+#             */
/*   Updated: 2022/11/16 12:17:03 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char	*dest, char const *s1, size_t j)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		dest[j] = s1[i];
		i++;
		j++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*ptr;
	size_t	s1len;

	len = ft_strlen(s1) + ft_strlen(s2);
	s1len = ft_strlen(s1);
	ptr = (char *)malloc (len + 1);
	if (!ptr)
		return (NULL);
	else
	{
		ptr = ft_strcat(ptr, s1, 0);
		ptr = ft_strcat(ptr, s2, s1len);
	}
	ptr[len] = '\0';
	return (ptr);
}
