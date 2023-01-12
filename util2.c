/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:35:10 by ebennamr          #+#    #+#             */
/*   Updated: 2023/01/12 16:09:21 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void free2(char **pt)
{
	int i;

	i = 0;
	while (pt[i])
	{
		free(pt[i]);
		i++;
	}
	free(pt);
}
t_int2 *create_t_int2(int len)
{
	t_int2 *	t;
	t = (t_int2 *) cmalloc(sizeof(t_int2));
	if (t == 0)
	return NULL;
	t->pt =  cmalloc(len * sizeof(int));
	if (t->pt == 0)
		return free(t), (t_int2 *) 0;
	t->len = len;
}


