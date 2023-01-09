/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:42:38 by ebennamr          #+#    #+#             */
/*   Updated: 2023/01/08 16:31:28 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int check_repeat(t_data *data, long nb)
{
	int i;

	i = 0;
	while (i < data->len_a)
	{
		if (data->a[i] == nb)
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
	data->a = (int *) malloc(len * sizeof(int));
	printf("split and malloc ok ");
	while (*num)
	{
		if (data->a && is_digit(*num) != TRUE)
			ft_error(ERROR);
		nb = ft_atoi(*num);
		if (nb > INT_MAX || nb < INT_MIN)
			ft_error(ERROR);
		check_repeat(data, nb);
		data->a[data->len_a] = (int) nb;
		data->len_a += 1;
		num++;
	}
free2((num - len));
}


