/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:21:21 by ebennamr          #+#    #+#             */
/*   Updated: 2023/01/12 16:08:37 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	fill(int *tab, int *t_len, int *t_index, int size, t_int2 *data)
{
	int	i;
	int	index;

	index = indexofmax(t_len, size);
	data->len = t_len[index];
	data->pt = malloc(t_len[index]);
	i = t_len[index] - 1;
	while (i >= 0)
	{
		data->pt[i] = tab[index];
		if (t_index[index] != -1)
			index = t_index[index];
		i--;
	}
}

void	get_lis(int *stack, int len, t_int2 *data)
{
	int	*lis;
	int	*lis_len;
	int	*lis_indx;
	int	i;
	int	j;

	j = 1;
	lis_len = allocset(len, 1);
	lis_indx = allocset(len, -1);

	while (j < len)
	{
		i = 0;
		while (i < j)
		{
			if (stack[i] < stack[j])
			{
				if ((lis_len[i] + 1) > lis_len[j])
				{
					lis_len[j] = lis_len[i] + 1;
					lis_indx[j] = i;
				}
			}
			i++;
		}
		j++;
	}
	fill(stack, lis_len, lis_indx, len, data);
}
