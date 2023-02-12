/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alogo1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:46:30 by ebennamr          #+#    #+#             */
/*   Updated: 2023/02/10 15:45:32 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void t_cmd_inint(t_cmd *t1)
{
	t1->a_move = -1;
	t1->a_type = 0;
	t1->b_move = -1;
	t1->b_type = 0;
}
static void	t_cmd_copy(t_cmd *t1,t_cmd *t2)
{
	t1->a_move = t2->a_move;
	t1->a_type = t2->a_type;
	t1->b_move = t2->b_move;
	t1->b_type = t2->b_type;
}
static void search_in_a(t_int2 *stack, t_cmd *t, int num)
{
	int i;
	int idx;

	idx = indexofmax(stack->pt, stack->len);
	i = 0;
	while (i < stack->len)
	{
		if (stack->pt[idx] < num)
			break;
		if (stack->pt[i] > num && stack->pt[i] < stack->pt[idx])
			idx = i;
		i++;
	}
	if (idx <= (stack->len / 2))
	{
		t->a_move = idx;
		t->a_type = TYPE_RX;
	}
	else
	{
		t->a_move =  stack->len - idx;
		t->a_type = TYPE_RRX;
	}
	if (indexofmax(stack->pt, stack->len) == idx && num > stack->pt[idx])
	{
		if(idx <= stack->len / 2)
		t->a_move += 1;
		else
		t->a_move -= 1;
	}
}
int num_of_inst(t_cmd t1)
{
	int mv;
	mv = 0;
	if (t1.a_type == t1.b_type)
	{
		mv = min(t1.a_move , t1.b_move);
		t1.a_move -= mv;
		t1.b_move -= mv;
		if ( t1.a_move > 0)
		mv += t1.a_move;
		if (t1.b_move > 0)
		mv += t1.b_move;
	}
	else
	mv =  t1.a_move + t1.b_move;

	return (mv);
}
t_cmd	searchofbest_move(t_data *data)
{
	t_cmd t1;
	t_cmd t2;
	int i;
	int center;

	t_cmd_inint(&t1);
	t_cmd_inint(&t2);
	i = 0;
	center = data->stack_b->len / 2;
	while (i < data->stack_b->len)
	{
		search_in_a(data->stack_a, &t2,data->stack_b->pt[i]);
		if (i <= center)
		{
			t2.b_move = i;
			t2.b_type = TYPE_RX;
		}
		else
		{

			t2.b_move = ( data->stack_b->len - i);
			t2.b_type = TYPE_RRX;
		}

	//if (t1.a_move < 0 || (t2.a_move + t2.b_move) < (t1.a_move + t1.b_move))
		if (t1.a_move < 0 || num_of_inst(t2) < num_of_inst(t1))
		{
			t_cmd_copy(&t1, &t2);
		}

		i++;
	}
	return t1;
}




