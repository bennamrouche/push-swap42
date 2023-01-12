/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:51:41 by ebennamr          #+#    #+#             */
/*   Updated: 2023/01/12 16:07:33 by ebennamr         ###   ########.fr       */
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
	sx(data->stack_a.pt, data->stack_a.len, 0);
	sx(data->stack_b.pt,data->stack_b.len, 0);
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
	rx(data->stack_a.pt, data->stack_a.len, 0);
	rx(data->stack_b.pt, data->stack_b.len, 0);
	write(1, RR, 3);
}
