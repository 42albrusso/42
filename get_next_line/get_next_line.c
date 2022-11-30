/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:13:46 by albrusso          #+#    #+#             */
/*   Updated: 2022/11/30 17:35:25 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "get_next_line.h"

void ft_free(char *ptr)
{
	if (!*ptr)
	{
		free(ptr);
		ptr = 0;
	}
}

char	*ft_ret(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	ret = (char *)ft_calloc(i + 2, 1);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\n';
	if (str == NULL)
		ret = NULL;
	return (ret);
}

char	*ft_read(int fd, char *str)
{
	int		byte_read;
	char	*s;

	byte_read = 1;
	while (byte_read > 0)
	{
		s = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
		byte_read = read (fd, s, BUFFER_SIZE);
		if (byte_read == 0)
			break ;
		str = ft_strjoin(str, s);
		if (ft_strchr(str, '\n') == 1)
			break ;
	}
	if (byte_read == 0)
		free (s);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!str)
		str = ft_calloc(1, 1);
	str = ft_read(fd, str);
	ret = ft_ret(str);
	if (str[0] == 0)
	{
		free (str);
		str = NULL;
		return (str);
	}
	str = ft_strdup(str);
	return (ret);
}

int	main(void)

{
	int		fd;
	int		i;
	char	*s;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	while (i < 3)
	{
		s = get_next_line(fd);
		printf("%d. %s", i, s);
		i++;
		free(s);
	}
	return (0);
}
