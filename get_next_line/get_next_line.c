/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:47:03 by albrusso          #+#    #+#             */
/*   Updated: 2022/12/06 18:02:39 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*ft_ret(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	if (str[0] == 0)
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	ret = (char *)ft_calloc(i + 1, 1);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		ret[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		ret[i] = '\n';
	return (ret);
}

char	*ft_read(int fd, char *str)
{
	int		byte_read;
	char	*s;

	byte_read = 1;
	if (!str)
		str = ft_calloc(1, 1);
	while (byte_read > 0)
	{
		s = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
		byte_read = read (fd, s, BUFFER_SIZE);
		str = ft_strjoin(str, s);
		if (byte_read == 0)
			break ;
		if (ft_strchr(str, '\n') == 1)
			break ;
	}
	if (str[0] == 0 && byte_read == 0)
	{
		free (str);
		str = NULL;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	str = ft_read(fd, str);
	if (str == NULL)
	{
		ret = NULL;
		free (str);
		return (ret);
	}
	ret = ft_ret(str);
	str = ft_strdup(str);
	return (ret);
}

