/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:51:41 by ebennamr          #+#    #+#             */
/*   Updated: 2023/02/07 18:06:48 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pushswap.h"

void rrx(t_int2 *tab, char *str)
{
	int i;
	int tmp;

	if (tab->len < 2)
		return;
	tmp = tab->pt[tab->len - 1];
	i = tab->len - 1;
	while (i > 0)
	{
		tab->pt[i] = tab->pt[i - 1];
		i--;
	}
	tab->pt[0] = tmp;
	if (str != 0)
		write(1, str, 4);
}

void rrr(t_data *data)
{
	rrx(data->stack_a, 0);
	rrx(data->stack_b, 0);
	write(1, "rrr\n", 4);
}
void px(t_int2 *tab1, t_int2 *tab2, int max, char *str)
{
	int i;

	i = ++(tab2->len);
	if (max <= tab2->len && tab1->len <= 0)
		return;

	while (i-- > 0)
	{
		tab2->pt[i] = tab2->pt[i - 1];
	}
	tab2->pt[0] = tab1->pt[0];
	i = -1;
	while (++i < tab1->len - 1)
	{
		tab1->pt[i] = tab1->pt[i + 1];
	}
	tab1->pt[tab1->len - 1] = 0;
	(tab1->len)--;
	if (str != 0)
		write(1, str, ft_strlen(str));
}
