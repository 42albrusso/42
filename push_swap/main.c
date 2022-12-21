/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:37:53 by albrusso          #+#    #+#             */
/*   Updated: 2022/12/21 11:53:37 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	checkNumber(int ac, char *av[])
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while(i < ac)
	{
		while(av[i][j])
		{
			if (av[i][j] >= '0' && av[i][j] <= '9')
				
			j++;
		}
		i++;
	}
}

int	error(void)
{
	write (1, "Error\n", 6);
	return (0);
}

int	main(int argc, char *argv[])
{
	c_list	a;
	
	if (argc == 1)
		return (error());
	else
	{

	}
}
