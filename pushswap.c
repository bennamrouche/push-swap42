/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:01:53 by ebennamr          #+#    #+#             */
/*   Updated: 2023/01/08 16:20:49 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_data	data;
	char	*tmp;

	if (ac == 1)
		ft_error(ERROR);
	tmp = join_args(ac, av);
	printf("join ok ");
	parse(&data, tmp);
int ii = 0;
while (ii < data.len_a)
{
printf("[ %d ] ", data.a[ii]);
ii++;
}

	

}
