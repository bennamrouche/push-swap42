/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alogo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:46:30 by ebennamr          #+#    #+#             */
/*   Updated: 2023/02/06 15:37:58 by ebennamr         ###   ########.fr       */
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
void search_in_a(t_int2 *stack, t_cmd *t, int num)
{
	int i;
	int idx;

	idx = indexofmax(stack->pt, stack->len);
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
		t->a_move = (idx - (stack->len / 2));
		t->a_type = TYPE_RRX;
	}
	//printf("index[%d] %d %d %d %d \n", i, t->a_move, t->a_type, t->b_move, t->b_type);
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
			//printf("index[%d RX] %d %d %d %d \n", i, t2.a_move, t2.a_type, t2.b_move, t2.b_type);
			//printf("RRX T2");
		}
		else
		{
			t2.b_move = (i - center);
			t2.b_type = TYPE_RRX;
			//printf("RX T2");
		}
		// if ((t1.a_move < 0 || t2.a_move + t2.b_move) < (t1.a_move + t1.b_move))
		if (1){
			//t_cmd_copy(&t1, &t2);
			//printf("copy in [%d]",i);
			puts("hi");
		}

		i++;
	}
	return t1;
}


