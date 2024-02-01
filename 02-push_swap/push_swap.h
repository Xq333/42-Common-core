/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:55:45 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/01/18 13:06:38 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

/*----- Struct creation -----*/

/* Definition of the stack */
typedef struct s_elem {
	int				v;
	struct s_elem	*previous;
	struct s_elem	*next;
}				t_elem;

/* Definition of the stack structure */
typedef struct s_stack {
	int				length;
	struct s_elem	*s;
	struct s_elem	*end;
}				*t_stack;

/* Definition of the push swap structure */
typedef struct s_pswap {
	struct s_stack	*a;
	struct s_stack	*b;
	int				moves;
}				t_pswap;

/*----- Stack utils -----*/

/* Create the stack */
t_stack	newstack(void);
/* Check if the stack is empty */
int		is_empty(t_stack stack);
/* Return the stack length */
int		stack_length(t_stack stack);
/* Return the first value of the stack */
int		stack_first(t_stack stack);
/* Return the last value of the stack */
int		stack_last(t_stack stack);
/* Add the value nb at the back of the stack a */
void	insert_values_backa(t_pswap *p, int nb);
/* Add the value nb at the front of the stack a */
void	insert_values_fronta(t_pswap *p, int nb);
/* Add the value nb at the back of the stack b */
void	insert_values_backb(t_pswap *p, int nb);
/* Add the value nb at the front of the stack b */
void	insert_values_frontb(t_pswap *p, int nb);
/* Delete the value at the back of the stack a */
void	del_values_backa(t_pswap *p);
/* Delete the value at the front of the stack a */
void	del_values_fronta(t_pswap *p);
/* Delete the value at the front of the stack b */
void	del_values_frontb(t_pswap *p);
/* Delete the value at the back of the stack b */
void	del_values_backb(t_pswap *p);

/*----- Utils ------*/

long	ft_atol(const char *str);
void	printerror(void);
int		findminus(t_stack p);
void	maxfirst(t_pswap *p);
int		findindex(t_stack p, int nb);
int		findmaxis(t_stack p);
int		findnextmin(t_stack p, int rep);
int		findstackmin(t_stack p, int tmp);
int		findclosest(t_stack p, int tmp);
void	sortpart1(t_pswap *p, int stack, int mediane);
char	**ft_split(const char *s, char c);
int		findstackmediane(t_stack p, int tmp);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s);
void	*ft_memcpy(void *d, const void *s, size_t size);
void	ft_print_instruction(char *action);
void	sortpart3(t_pswap *p);
int		findclosestn(t_stack p, int tmp);
void	push(t_pswap *p);
int		findnextmaxis(t_stack p, int rep);
void	is_doublon(char **argv, int argc, int x);

/*----- Moves -----*/
void	sa(t_pswap *p);
void	sb(t_pswap *p);
void	pa(t_pswap *p);
void	pb(t_pswap *p);
void	ra(t_pswap *p);
void	rb(t_pswap *p);
void	rra(t_pswap *p);
void	rrb(t_pswap *p);

/*----- Sort algorithm -----*/
void	algorithm(t_pswap *p);

#endif
