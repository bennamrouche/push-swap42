/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:01:28 by ebennamr          #+#    #+#             */
/*   Updated: 2023/01/09 20:42:26 by ebennamr         ###   ########.fr       */
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
size_t ft_strlen2( char **str)
{
int len;

len = 0;

	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}
void *cmalloc(size_t len)
{
	char *pt;
	size_t i;

	pt = malloc(len);
	i = 0 ;
	if (pt == 0)
		return 0;
	while (i < len)
	{
		pt[i] = 0;
		i++;
	}
	return (void *)pt;
}
int *intset(int *tab ,int size,int set)
{
	int i;

	i = 0;
	while (i < size)
	{
		tab[i] = set;
		i++;
	}
	return (tab);
}
