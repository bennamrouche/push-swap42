/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:07:44 by ebennamr          #+#    #+#             */
/*   Updated: 2023/01/04 20:14:27 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

size_t	ft_strlen( char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*p;

	if (!s)
		return (NULL);
	if (len <= ft_strlen(s + start))
		p = (char *)(malloc(len + 1));
	else
		p = (char *)(malloc(ft_strlen(s + start) + 1));
	j = 0;
	if (!p || !s)
	{
		return (0);
	}
	while (s[start] && j < len && start < ft_strlen(s))
	{
		p[j] = s[start];
		j++;
		start++;
	}
	p[j] = '\0';
	return (p);
}

char	*ft_strjoin(char *src1, char *src2)
{
	int		len;
	int		count;
	char	*pt;

	if (!src1 || !src2)
		return (0);
	len = ft_strlen(src1) + ft_strlen(src2);
	count = 0;
	pt = malloc(len + 1);
	if (!pt)
		return (0);
	while (src1[count])
	{
		*(pt++) = src1[count];
		count++;
	}
	count = 0;
	while (src2[count])
	{
		*(pt++) = src2[count];
		count++;
	}
	*pt = '\0';
	return (pt - len);
}

void	ft_error(char *err)
{
	write(2, err, ft_strlen(err));
	exit(1);
}

long	ft_atoi(char *str)
{
	long	i;
	long	mult;
	long	nb;

	mult = 1;
	nb = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mult *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	nb *= mult;
	return (nb);
}
