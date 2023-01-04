/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:42:38 by ebennamr          #+#    #+#             */
/*   Updated: 2023/01/04 21:39:29 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

int check(t_data *data, char *args)
{
	char **num ;

	num = ft_split(args, ' ');
	while (*num)
	{
		if (is_digit(num) != TRUE)
			return (FALSE);
		if (is)
	}

}
