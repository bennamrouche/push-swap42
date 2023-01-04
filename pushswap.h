/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:22:52 by ebennamr          #+#    #+#             */
/*   Updated: 2023/01/04 21:24:34 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "string.h"
# include <stdlib.h>
# include <unistd.h>
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
typedef struct s_data
{
	int *a;
	int *b;
	int len_a;
	int leb_b;

}t_data;

char *join_args(int ac, char **arg);

#endif
