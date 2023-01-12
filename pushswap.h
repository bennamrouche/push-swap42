/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:22:52 by ebennamr          #+#    #+#             */
/*   Updated: 2023/01/12 15:52:06 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "string.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
// define instruction
# define ERROR "Error\n"
# define SA  "sa\n"
# define SB  "sb\n"
# define SS  "ss\n"
# define PA  "pa\n"
# define PB  "pb\n"
# define RA  "ra\n"
# define PB  "pb\n"
# define RR  "rr\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"
// dfine boolean var
# define TRUE  1
# define FALSE 0

typedef struct s_int2
{
	int	*pt;
	int	len;
}t_int2;

typedef struct s_data
{
	t_int2	stack_a;
	t_int2	stack_b;
	int		maxisze;
}t_data;
//util 1
char	*join_args(int ac, char **arg);
void	parse(t_data *data, char *args);
void	free2(char **pt);
//util 2
t_int2	*create_t_int2(int len);

	// array
int		indexofmax(int *arr, int len);
int		*intset(int *tab, int size, int set);
int *allocset(int len, int set);

#endif
