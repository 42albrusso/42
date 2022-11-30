/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:02:38 by albrusso          #+#    #+#             */
/*   Updated: 2022/11/11 15:48:16 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ptr;
	int		i;

	i = ft_strlen(str);
	while (i > 0 && str[i] != (char)c)
		i--;
	if (str[i] == (char)c)
	{
		ptr = (char *)(str + i);
		return (ptr);
	}
	else
		return (NULL);
}
