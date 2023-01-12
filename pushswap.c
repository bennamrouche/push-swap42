/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:01:53 by ebennamr          #+#    #+#             */
/*   Updated: 2023/01/12 16:35:45 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

static void	step1_parse(t_data *data, int ac, char **av)
{
	char	*tmp;

	tmp = join_args(ac, av);
	parse(data, tmp);
}
int	main(int ac, char **av)
{
	t_data	data;
printf("hi");
	if (ac == 1)
		ft_error(ERROR);
	step1_parse(&data, ac ,av);
int i = 0;
 printf("max = %d \n", data.maxisze);
while (i < data.maxisze)
{
	printf("%d ", data.stack_a.pt[i]);
i++;
}





}
