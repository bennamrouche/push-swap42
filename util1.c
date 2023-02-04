/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:42:38 by ebennamr          #+#    #+#             */
/*   Updated: 2023/01/15 21:32:18 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int check_repeat(t_data *data, long nb)
{
	int i;

	i = 0;
	while (i < data->stack_a->len)
	{
		if (data->stack_a->pt[i] == nb)
			ft_error(ERROR);
		i++;
	}

	return (TRUE);
}

char	*join_args(int ac, char **arg)
{
	char	*tmp;
	char	*mid;
	int		i;

	i = 1;
	tmp = (char *)malloc(1);
	*tmp = '\0';
	while (i < ac)
	{
		mid = ft_strjoin(tmp, " ");
		free(tmp);
		if (mid == 0)
			ft_error(ERROR);
		tmp = ft_strjoin(mid, arg[i]);
			free(mid);
		if (tmp == 0)
			ft_error(ERROR);
		i++;
	}
	return tmp;
}


void parse(t_data *data, char *args)
{
	char	**num;
	size_t	len;
	long nb;

	num = ft_split(args, ' ');
	len = ft_strlen2(num);
	data->stack_a = create_t_int2(len);
	data->stack_a->len = 0;
	while (*num)
	{
		if (data->stack_a->pt && is_digit(*num) != TRUE)
			ft_error(ERROR);
		nb = ft_atoi(*num);
		if (nb > INT_MAX || nb < INT_MIN)
			ft_error(ERROR);
		check_repeat(data, nb);
		data->stack_a->pt[data->stack_a->len] = (int) nb;
		data->stack_a->len += 1;
		num++;
	}
	data->maxisze = len;
	data->stack_b = create_t_int2(len);
	data->stack_b->len = 0;
free2((num - len));
}


