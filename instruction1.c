/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:51:41 by ebennamr          #+#    #+#             */
/*   Updated: 2023/01/08 18:50:47 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pushswap.h"

void sx(int *tab, int len, char *str)
{
	if (len < 2)
		return;
	int tmp;

	tmp = *(tab + 1);
	*(tab + 1) = *tab;
	*tab = tmp;
	if (str != 0)
		write(1, str, ft_strlen(str));
}

void ss(t_data *data)
{
	sx(data->a, data->len_a, 0);
	sx(data->b,data->leb_b, 0);
	write(1, SS, 3);
}
void rx(int *tab, int len, char *str)
{
	int i;
	int tmp;

	i = 0;
	if (len < 2)
		return;
	tmp = tab[0];
	while (i < len - 1)
	{
		tab[i] = tab[i + 1];
		i++;
	}
	tab[i] = tmp;
}
void rr(t_data *data)
{
	rx(data->a, data->len_a, 0);
	rx(data->b, data->leb_b, 0);
	write(1, RR, 3);
}
