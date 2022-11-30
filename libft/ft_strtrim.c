/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:02:18 by albrusso          #+#    #+#             */
/*   Updated: 2022/11/11 15:48:17 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_check(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strtrimmed;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	while (s1[i] && ft_check(s1[i], set))
		i++;
	j = ft_strlen(s1);
	while (j > i && ft_check(s1[j - 1], set))
		j--;
	strtrimmed = (char *)malloc((j - i + 1));
	if (!strtrimmed)
		return (NULL);
	k = 0;
	while (i < j)
		strtrimmed[k++] = s1[i++];
	strtrimmed[k] = '\0';
	return (strtrimmed);
}
