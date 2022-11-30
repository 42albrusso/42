/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:03:58 by albrusso          #+#    #+#             */
/*   Updated: 2022/11/11 15:48:01 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_counter(char const *s, char c)
{
	int		i;

	i = 0;
	if (*s && *s != c)
		i++;
	while (*s && *(s + 1))
	{
		if (*s == c && *(s + 1) != c)
			i++;
		s++;
	}
	return (i + 1);
}

int	leng(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i + 1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		total;
	int		len;
	int		i;

	i = 0;
	total = ft_counter(s, c);
	arr = ft_calloc(total * sizeof(char *), 1);
	if (!arr)
		return (NULL);
	while (*s && i < total - 1 && total != 1)
	{
		while (*s == c)
			s++;
		len = leng(s, c);
		arr[i] = malloc(len);
		if (!arr[i])
			return (NULL);
		ft_strlcpy(arr[i], s, len);
		i++;
		s += len - 1;
	}
	return (arr);
}
