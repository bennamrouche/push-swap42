/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:22:52 by ebennamr          #+#    #+#             */
/*   Updated: 2023/02/04 11:12:59 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "string.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
#include <stdio.h>
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
	t_int2	*stack_a;
	t_int2	*stack_b;
	int		maxisze;
}t_data;
//util 1
char	*join_args(int ac, char **arg);
void	parse(t_data *data, char *args);
void	free2(char **pt);
//util 2
t_int2	*create_t_int2(int len);
void		free_t_int(t_int2 *fr);

	// array1
int		indexofmax(int *arr, int len);
int		*intset(int *tab, int size, int set);
int*	allocset(int len, int set);
void	checksort(t_int2 *stack);
int		isexits(t_int2 *tab, int num);
// array2
int	array_isequal(t_int2 *tab1, t_int2 *tab2);

// inscution1
void sx(t_int2 *tab, char *str);
void	ss(t_data *data);
void	rx(t_int2 *tab, char *str);
void	rr(t_data *data);
//inscution2
void	rrx(t_int2 *tab, char *str);
void	rrr(t_data *data);
void	px(t_int2 *tab1, t_int2 *tab2, int max, char *str);
// lis
t_int2	*get_lis(int *stack, int len);
void	extract_lis(t_data *data, t_int2 *lis_list);
#endif
