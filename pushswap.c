/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:01:53 by ebennamr          #+#    #+#             */
/*   Updated: 2023/02/04 12:12:33 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

static void	step1(t_data *data, int ac, char **av)
{
	char	*tmp;

	tmp = join_args(ac, av);
	 parse(data, tmp);
	checksort(data->stack_a);
	t_int2 *boot = get_lis(data->stack_a->pt, data->stack_a->len);
		printf(" <-sub -> ");



		printf("---- lis ----\n");
		for (size_t i = 0; i < boot->len; i++)
		{
			printf("%d ", boot->pt[i]);
	}
printf("----- stack -----\n");
	for (size_t i = 0; i < data->stack_a->len; i++)
	{
		printf("%d ", data->stack_a->pt[i]);
	}
	printf("\n");
	extract_lis(data, boot);
}
int	main(int ac, char **av)
{
	t_data	data;
	if (ac == 1)
		ft_error(ERROR);
	step1(&data, ac ,av);




}
