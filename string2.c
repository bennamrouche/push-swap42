/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:01:28 by ebennamr          #+#    #+#             */
/*   Updated: 2023/02/13 16:34:40 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_digit(char *str)
{
	if (*str && (*str == '+' || *str == '-'))
		str++;
	if (*str == '\0')
		return (FALSE);
	while (*str)
	{
		if (*str > '9' || *str < '0')
			return (FALSE);
		str++;
	}
	return (TRUE);
}

size_t	ft_strlen2( char **str)
{
	int	len;

len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

void	*malloc_set(size_t len)
{
	char	*pt;
	size_t	i;

	pt = malloc(len);
	i = 0 ;
	if (pt == 0)
		return (0);
	while (i < len)
	{
		pt[i] = 0;
		i++;
	}
	return ((void *)(pt));
}

int	min(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

void	free2(char **pt)
{
	int	i;

	i = 0;
	while (pt[i])
	{
		free(pt[i]);
		i++;
	}
	free(pt);
}
