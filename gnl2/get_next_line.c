/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:13:46 by albrusso          #+#    #+#             */
/*   Updated: 2022/12/05 15:26:53 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	count_words(const char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == c)
			j++;
		i++;
	}
	return (j);
}

char	*ft_ret(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	if (str[0] == 0)
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	ret = (char *)ft_calloc(i + 2, 1);
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
	str = ft_calloc(1, 1);
	while (1)
	{
		s = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
		byte_read = read (fd, s, BUFFER_SIZE);
		if (byte_read == 0)
			break ;
		str = ft_strjoin(str, s);
	}
	free (s);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*ret;
	static int	x;
	static int	y;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!str)
	{
		str = ft_read(fd, str);
		x = count_words(str, '\n');
		y = -1;
	}
	if (x == y)
		free (str);
	if (y++ < x)
	{
		ret = ft_ret(str);
		str = ft_strdup(str);
	}
	else
		return (NULL);
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
	while (i < 1)
	{
		s = get_next_line(fd);
		printf("%d. %s", i, s);
		i++;
		free(s);
	}
	return (0);
}

