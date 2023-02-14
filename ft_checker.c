/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:31:19 by ebennamr          #+#    #+#             */
/*   Updated: 2023/02/14 16:38:56 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	excute(t_data *data, char *pt)
{
	if (ft_strcmp(pt, RA) == 0)
		rx(data->stack_a,0);
	else if (ft_strcmp(pt, RB) == 0)
		rx(data->stack_b, 0);
	else if (ft_strcmp(pt, RR) == 0)
		rr(data, 0);
	else if (ft_strcmp(pt, RRA) == 0)
		rrx(data->stack_a, 0);
	else if (ft_strcmp(pt, RRB) == 0)
		rrx(data->stack_b, 0);
	else if (ft_strcmp(pt, RRR) == 0)
		rrr(data, 0);
	else if (ft_strcmp(pt, SA) == 0)
		sx(data->stack_a, 0);
	else if (ft_strcmp(pt, SB) == 0)
		sx(data->stack_b, 0);
	else if (ft_strcmp(pt, SS) == 0)
		ss(data, 0);
	else if (ft_strcmp(pt, PA) == 0)
		px(data->stack_b, data->stack_a, data->maxisze, 0);
	else if (ft_strcmp(pt, PB) == 0)
		px(data->stack_a, data->stack_b, data->maxisze, 0);
	else
		ft_error(ERROR);
}

void	read_ins(t_data *data)
{

	char	*input;
	char	c;
	int		i;

	i = 0;
	c = '\0';
	input = malloc_set(6);
	while (read(0, &c,1) > 0)
	{
		if (i < 5)
			input[i] = c;
		if (c == '\n')
		{
			excute(data, input);
			i = 0;
			ft_bzero(input, 6);
			c = '\0';
			continue ;
		}
		i++;
	}
	free(input);
}

static int	ft_checksort(t_int2 *stack)
{
	int	i;

	if (stack->len < 1)
		exit(0);
	i = 0;
	while (i < stack->len - 1)
	{
		if (stack->pt[i] > stack->pt[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int main(int ac, char **av)
{
	t_data	data;
	char *tmp;

	if (ac == 1)
		exit(0);
	tmp = join_args(ac, av);
	parse(&data, tmp);
	read_ins(&data);
	free(tmp);
	if (ft_checksort(data.stack_a) == TRUE && data.stack_b->len == 0)
		write(1,OK, 3);
	else
		write(1, KO, 3);
		system("leaks checker");
}
