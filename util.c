/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:42:38 by ebennamr          #+#    #+#             */
/*   Updated: 2023/02/13 15:57:35 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	check_repeat(t_data *data, long nb)
{
	int	i;

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
	return (tmp);
}

void	parse(t_data *data, char *args)
{
	char	**num;
	size_t	len;
	long	nb;

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

t_int2	*create_t_int2(int len)
{
	t_int2	*t;

	t = (t_int2 *)malloc_set(sizeof(t_int2));
	if (t == 0)
		return (NULL);
	t->pt = malloc_set(len * sizeof(int));
	if (t->pt == 0)
	{
		free(t);
		return (0);
	}
	t->len = len;
	return (t);
}

int	array_isequal(t_int2 *tab1, t_int2 *tab2)
{
	int	i;

	i = 0;
	if (tab1->len != tab2->len)
		return (FALSE);
	while (i < tab1->len)
	{
		if (isexits(tab1, tab2->pt[i]) != TRUE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
