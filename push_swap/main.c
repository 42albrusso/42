/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:13:23 by albrusso          #+#    #+#             */
/*   Updated: 2022/12/13 19:05:31 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	ft_nbrcheck(int ac, char *av[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ac)
	{
		while (av[i][j])
		{
			if (av[i][j] > '0' && av[i][j] < '9')
				j++;
			else if (av[i][j] == '-' || av[i][j] == '+')
			{
				if (j == 0)
					j++;
				else
					return (0);
			}
			else
				return (0);
		}
		i++;
	}
	return (1);
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
		if (ft_nbrcheck(argc, argv) == 0)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		a = ft_new(argc, argv, a);
		b = (int *)malloc((argc - 1) * sizeof(int));
		
	}
}