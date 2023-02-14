/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:01:53 by ebennamr          #+#    #+#             */
/*   Updated: 2023/02/14 16:13:15 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

static void	tree_sort(t_int2 *t, int im)
{
	if (im == 0 && t->pt[1] > t->pt[2])
	{
		rx(t, RA);
		sx(t, SA);
	}
	else if (im == 0 && t->pt[1] < t->pt[2])
		rx(t, RA);
	else if (im == 1 && t->pt[0] > t->pt[2])
		rrx(t, RRA);
	else if (im == 1 && t->pt[0] < t->pt[2])
	{
		rrx(t, RRA);
		sx(t, SA);
	}
	else if (im == 2 && t->pt[0] > t->pt[1])
		sx(t, SA);
}

static void	alogo(t_data *data)
{
	t_cmd	cmd;

	while (data->stack_b->len > 0)
	{
		cmd = searchofbest_move(data);
		excute_move(data, cmd);
	}
	rotate_to_sort(data);
}

static void	step2(t_data *data)
{
	t_int2	*lis;

	if (data->stack_a->len == 2)
		rotate_to_sort(data);
	else if (data->stack_a->len == 3)
		tree_sort(data->stack_a, indexofmax(data->stack_a->pt, 3));
	else if (data->stack_a->len == 5)
	{
		px(data->stack_a, data->stack_b, data->maxisze, PB);
		px(data->stack_a, data->stack_b, data->maxisze, PB);
		tree_sort(data->stack_a, indexofmax(data->stack_a->pt, 3));
		alogo(data);
	}
	else
	{
		lis = get_lis(data->stack_a->pt, data->stack_a->len);
		extract_lis(data, lis);
		alogo(data);
		free(lis->pt);
		free(lis);
	}
}

static void	step1(t_data *data, int ac, char **av)
{
	char	*tmp;

	tmp = join_args(ac, av);
	parse(data, tmp);
	checksort(data->stack_a);
	free(tmp);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 1)
		exit(0);
	step1(&data, ac, av);
	step2(&data);
	//system("leaks push_swap");
	checksort(data.stack_a);
}
