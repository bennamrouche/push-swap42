/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:51:41 by ebennamr          #+#    #+#             */
/*   Updated: 2023/01/09 20:29:38 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pushswap.h"

void rrx(int *tab, int len, char *str)
{
	int i;
	int tmp;

	if (len < 2)
		return;
	tmp = tab[len - 1];
	i = len - 1;
	while (i > 0)
	{
		tab[i] = tab[i - 1];
		i--;
	}
	tab[0] = tmp;
	if (str != 0)
		write(1, str, 3);
}

void rrr(t_data *data)
{
	rrx(data->a, data->len_a, 0);
	rrx(data->b, data->leb_b, 0);
	write(1, "rrx\n", 4);
}
void px(int *tab1, int *len1, int *tab2, int *len2, int max)
{
	int i;

	i = ++(*len2);
	if (max <= *len2 && *len1 <= 0)
		return;

	while (i-- > 0)
	{
		tab2[i] = tab2[i - 1];
	}
	tab2[0] = tab1[0];
	i = -1;
	while (++i < *len1 - 1)
	{
		tab1[i] = tab1[i + 1];
	}
	tab1[*len1 - 1] = 0;
	(*len1)--;
}
