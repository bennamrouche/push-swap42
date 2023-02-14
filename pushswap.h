/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:22:52 by ebennamr          #+#    #+#             */
/*   Updated: 2023/02/14 16:01:22 by ebennamr         ###   ########.fr       */
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
# define RB  "rb\n"
# define RR  "rr\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"
# define TYPE_RX 0
# define TYPE_RRX 1
# define OK "OK\n"
# define KO "KO\n"
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

typedef struct s_cmd
{
	int	a_type;
	int	a_move;
	int	b_type;
	int	b_move;
}t_cmd;

//util 1
char		*join_args(int ac, char **arg);
void		parse(t_data *data, char *args);
void		free2(char **pt);
//util 2
t_int2		*create_t_int2(int len);
void		free_t_int(t_int2 *fr);

	// array1
int			indexofmax(int *arr, int len);
int			*intset(int *tab, int size, int set);
int			*allocset(int len, int set);
void		checksort(t_int2 *stack);
int			isexits(t_int2 *tab, int num);
// array2
int			array_isequal(t_int2 *tab1, t_int2 *tab2);

// inscution1
void		sx(t_int2 *tab, char *str);
void		ss(t_data *data, char *str);
void		rx(t_int2 *tab, char *str);
void		rr(t_data *data, char *str);
// inscution2
void		rrx(t_int2 *tab, char *str);
void		rrr(t_data *data, char *str);
void		px(t_int2 *tab1, t_int2 *tab2, int max, char *str);
// lis
t_int2		*get_lis(int *stack, int len);
void		extract_lis(t_data *data, t_int2 *lis_list);
// alogo1
t_cmd		searchofbest_move(t_data *data);
// algo2
void		excute_move(t_data *data, t_cmd t);
void		rotate_to_sort(t_data *data);
//
size_t		ft_strlen(char *str);
char		*ft_substr(char *s, unsigned int start, size_t len);
char		**ft_split(char *s, char c);
char		*ft_strjoin(char *src1, char *src2);
void		ft_error(char *err);
long		ft_atoi(char *str);

int			is_digit(char *str);
size_t		ft_strlen2(char **str);
void		*malloc_set(size_t len);
int			min(int x, int y);
int			ft_strcmp(char *s1, char *s2);
void	ft_bzero(void *pt, int n);
#endif
