/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:53:34 by ebennamr          #+#    #+#             */
/*   Updated: 2023/01/04 21:27:47 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


static char	**free_all(char **list)
{
	size_t	j;

	j = 0;
	while (list[j])
	{
		free(list[j]);
		j++;
	}
	free(list);
	ft_error(ERROR);
	return (0);
}

static size_t	count_words(char const *string, char c)
{
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	while (string[i] == c)
		i++;
	while (string[i])
	{
		if (!string[i + 1] || (string[i] == c && string[i + 1] != c))
		{
			count++;
		}
		i++;
	}
	return (count);
}

char	**ft_split(char *s, char c)
{
	char	**split;
	size_t	i;
	size_t	count;
	size_t	save;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	split = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!split)
		return (0);
	while (i < count_words(s, c) && s[count] != '\0')
	{
		while (s[count] == c)
			count++;
		save = count;
		while (s[count] != c && s[count] != '\0')
			count++;
		split[i] = ft_substr(&s[save], 0, count - save);
		if (split[i++] == 0)
			return (free_all(split));
	}
	split[i] = 0;
	return (split);
}
