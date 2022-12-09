/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:05:22 by albrusso          #+#    #+#             */
/*   Updated: 2022/12/09 17:05:24 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	ft_swapA(int *a)
{
	int	n;
	if (!a[0] || !a[1])
		return ;
	n = a[0];
	a[0] = a[1];
	a[1] = n;
}

void	ft_swapB(int *b)
{
	int	n;

	if (!b[0] || !b[1])
		return ;
	n = b[0];
	b[0] = b[1];
	b[1] = n;
}

void	ft_swapAB(int *a, int *b)
{
	ft_swapA(a);
	ft_swapB(b);
}