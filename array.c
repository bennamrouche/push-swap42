/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:19:18 by ebennamr          #+#    #+#             */
/*   Updated: 2023/01/12 15:52:26 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	indexofmax(int *arr, int len)
{
	int	i;
	int	index;
	int	max;

	index = 0;
	i = 0;
	max = arr[0];
	while (i < len)
	{
		if (max < arr[i])
		{
			max = arr[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	*intset(int *tab, int size, int set)
{
	int	i;

	i = 0;
	while (i < size)
	{
		tab[i] = set;
		i++;
	}
	return (tab);
}
int *allocset(int len, int set)
{
	int *addr;

	addr = (int *)cmalloc(len * sizeof(int));
	if (addr == 0)
		return 0;
	intset(addr, len, set);
	return (addr);
}
