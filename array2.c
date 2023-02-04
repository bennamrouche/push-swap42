/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:02:36 by ebennamr          #+#    #+#             */
/*   Updated: 2023/02/04 11:12:09 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	array_isequal(t_int2 *tab1,t_int2 *tab2)
{
	int	i;

	i = 0;
	if (tab1->len != tab2->len)
		return (FALSE);
	while (i < tab1->len)
	{
		if (isexits(tab1,tab2->pt[i]) != TRUE)
			return (FALSE);
	i++;
	}
	return (TRUE);
}



