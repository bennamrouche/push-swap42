/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:54:18 by ebennamr          #+#    #+#             */
/*   Updated: 2023/01/04 20:14:47 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# include <stdlib.h>

size_t		ft_strlen(char *str);
char		*ft_substr(char *s, unsigned int start, size_t len);
char		**ft_split(char *s, char c);
char		*ft_strjoin(char *src1, char *src2);
void		ft_error(char *err);
long		ft_atoi(char *str);

int			is_digit(char *str);
#endif
