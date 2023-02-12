/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alogo2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:43:43 by ebennamr          #+#    #+#             */
/*   Updated: 2023/02/10 17:30:59 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void repeat_double(t_data *data,int num,int type)
{
	while (num > 0)
	{
		if(type == TYPE_RRX)
		 rrr(data);
		 else
		 rr(data);
	num--;
	}

}

static void repeat_a(t_int2 *data,int type, int num)
{
	while (num > 0)
	{
		if (type == TYPE_RRX)
			rrx(data,RRA);
		else
		rx(data, RA);
		num--;
	}

}
static void repeat_b(t_int2 *data, int type, int num)
{
	while (num > 0)
	{
		if (type == TYPE_RRX)
		rrx(data, RRB);
		else
		rx(data, RB);
		num--;
	}
}

void excute_move(t_data *data, t_cmd t)
{
	int min_val;
	while (t.a_move > 0 || t.b_move > 0)
	{
		if (t.b_move && t.a_move && t.a_type == t.b_type)
		{
			repeat_double(data, min(t.a_move, t.b_move), t.a_type);
			min_val = min(t.a_move, t.b_move);
			t.a_move -= min_val;
			t.b_move -= min_val;
		}
		else
		{
			repeat_a(data->stack_a, t.a_type, t.a_move);
			repeat_b(data->stack_b, t.b_type, t.b_move);
			break;
		}
	}
	px(data->stack_b,data->stack_a,data->maxisze,PA);
}

void rotate_to_sort(t_data *data)
{
	int id = indexofmax(data->stack_a->pt, data->stack_a->len);
	if (id < data->stack_a->len / 2) /* <= rep <*/
		repeat_a(data->stack_a, TYPE_RX,id + 1);
	else
		repeat_a(data->stack_a, TYPE_RRX, data->stack_a->len - id - 1);
}
