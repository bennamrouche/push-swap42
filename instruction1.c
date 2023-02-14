/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:51:41 by ebennamr          #+#    #+#             */
/*   Updated: 2023/02/13 15:42:32 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sx(t_int2 *tab, char *str)
{
	int	tmp;

	if (tab->len < 2)
		return ;
	tmp = *(tab->pt + 1);
	*(tab->pt + 1) = *tab->pt;
	*tab->pt = tmp;
	if (str != 0)
		write(1, str, ft_strlen(str));
}

void	ss(t_data *data, char *str)
{
	sx(data->stack_a, 0);
	sx(data->stack_b, 0);
	if (str != 0)
		write(1, SS, 3);
}

void	rx(t_int2 *tab, char *str)
{
	int	i;
	int	tmp;

	i = 0;
	if (tab->len < 2)
		return ;
	tmp = tab->pt[0];
	while (i < tab->len - 1)
	{
		tab->pt[i] = tab->pt[i + 1];
		i++;
	}
	tab->pt[i] = tmp;
	if (str != 0)
		write(1, str, ft_strlen(str));
}

void	rr(t_data *data, char *str)
{
	rx(data->stack_a, 0);
	rx(data->stack_b, 0);
	if (str != 0)
		write(1, RR, 3);
}
