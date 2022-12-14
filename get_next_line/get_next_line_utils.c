/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:13:52 by albrusso          #+#    #+#             */
/*   Updated: 2022/12/09 12:23:24 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(const char *str, int c)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != (char)c)
		i++;
	if (str[i] == (char)c)
		return (1);
	else
		return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	char		*memory;
	size_t		i;

	i = 0;
	memory = malloc(count * size);
	if (memory == NULL)
		return (0);
	while (i < count * size)
	{
		memory[i] = 0;
		i++;
	}
	return (memory);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*buffer;

	i = 0;
	j = 0;
	if (s1)
		while (s1[i])
			i++;
	if (s2)
		while (s2[j])
			j++;
	buffer = (char *)ft_calloc(i + j + 1, 1);
	if (buffer == NULL)
		return (NULL);
	j = -1;
	while (s1[++j])
		buffer[j] = s1[j];
	j = -1;
	while (s2[++j])
		buffer[i + j] = s2[j];
	free(s1);
	free(s2);
	return (buffer);
}

char	*ft_strdup(char *str)
{
	size_t		i;
	size_t		j;
	size_t		k;
	char		*ptr;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	while (str[j])
		j++;
	ptr = (char *)ft_calloc(j - i + 1, 1);
	if (!ptr)
		return (NULL);
	k = 0;
	while (str[i])
	{
		ptr[k] = str[i];
		k++;
		i++;
	}
	free (str);
	return (ptr);
}
