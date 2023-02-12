/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:21:21 by ebennamr          #+#    #+#             */
/*   Updated: 2023/02/07 17:56:20 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	find_sub(int *stack, int *lis_len, int *lis_indx, int len)
{
	int	i;
	int	j;

	j = 1;
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

}
t_int2	*fill(int *tab, int *t_len, int *t_index, int size)
{
	int	i;
	int	index;
	t_int2 *sub;

	index = indexofmax(t_len, size);
	sub = create_t_int2(t_len[index]);
	if (sub == 0)
		ft_error(ERROR);
	i = t_len[index] - 1;
	while (i >= 0)
	{
		sub->pt[i] = tab[index];
		if (t_index[index] != -1)
			index = t_index[index];
		i--;
	}
	return (sub);
}

t_int2	*get_lis(int *stack, int len)
{
	int	*lis_len;
	int	*lis_indx;
	t_int2 *sub;

	lis_len = allocset(len, 1);
	lis_indx = allocset(len, -1);
	if(!lis_indx && !lis_len)
		ft_error(ERROR);
	find_sub(stack, lis_len, lis_indx, len);
	sub = fill(stack, lis_len, lis_indx, len);
	free(lis_indx);
	free(lis_len);
	return sub;
}
void extract_lis(t_data *data ,t_int2 *lis_list)
{
	while (array_isequal(data->stack_a,lis_list) != TRUE)
	{
		if (isexits(lis_list, data->stack_a->pt[0]))
			 rx(data->stack_a, RA);
		else
			 px(data->stack_a, data->stack_b, data->maxisze, PB);
}

}
