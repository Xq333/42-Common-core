/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:57:50 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/01/18 15:47:02 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

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
char	**ft_split(const char *s, char c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s);
void	*ft_memcpy(void *d, const void *s, size_t size);
void	is_doublon(char **argv, int argc, int x);
int		ft_strlen(const char *str);
void	checker(t_pswap *p);
void	ft_free(char **split);

//GNL utils
char	*ft_strjoin(char *s1, char *s2);
void	freeee(void *ptr);
int		ft_strlen2(char *str);
int		ft_strchr(char *str, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);

//GNL
char	*get_next_line(int fd);
char	*line_reader(int fd, char *line);
char	*ft_substr2(const char *s, unsigned int start, int len, char *buff);
char	*line_parser(char *line, int diff, char *buff);

/*----- Moves -----*/
void	sa(t_pswap *p);
void	sb(t_pswap *p);
void	ss(t_pswap *p);
void	pa(t_pswap *p);
void	pb(t_pswap *p);
void	ra(t_pswap *p);
void	rb(t_pswap *p);
void	rr(t_pswap *p);
void	rra(t_pswap *p);
void	rrb(t_pswap *p);
void	rrr(t_pswap *p);

#endif