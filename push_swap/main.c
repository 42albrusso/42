/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:13:23 by albrusso          #+#    #+#             */
/*   Updated: 2022/12/09 17:57:00 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

int	ft_empty(int *n, int *v, int ac)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	while (i < ac)
	{
		while (j < ac)
		{
			if (v[i] == n[j])
				c++;
			j++;
		}
		i++;
	}
	return (c);
}

int	*ft_new(int ac, char *av[], int *a)
{
	int	i;

	i = 1;
	a = (int *)malloc((ac - 1) * sizeof(int));
	if (!a)
		return(0);
	while (i < ac)
	{
		if (ft_atoi(av[i]) < -2147483648 || ft_atoi(av[i]) > 2147483647)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		a[i] = ft_atoi(av[i]);
		i++;
	}
	return (a);
}

int	main(int argc, char *argv[])
{
	int	*a;
	int	*b;
	if (argc == 1)
		return (0);
	else
	{
		a = ft_new(argc, argv, a);
		b = (int *)malloc((argc - 1) * sizeof(int));
	}
}