/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:26:55 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/06/22 12:19:22 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_printf
{
	int	len;
	int	nb;
	int	prec;
	int	plus;
	int	minus;
	int	space;
	int	htag;
	int	zero;
}	t_printf;

/*---   UTILITIES.C   ---*/

int			ft_atoi(const char *str);
char		*ft_strndup(char const *line, int start, int end);
int			ft_utoa_base(unsigned int nbr, char *base, t_printf *p);
size_t		ft_strlen(const char *str);
long int	ft_itoa_base(long int nbr, char *base, int flag, t_printf *p);

/*---   UTILITIES2.C   ---*/

int			ft_ptoa_base(size_t nbr, char *base);
int			isflag(char c);
int			getlen(char *str, int i, t_printf *p, char c);
int			flags(t_printf *p, char *str, int i);
int			putstr(char *str, t_printf *p);

/*---   UTILITIES3.C   ---*/

int			ft_utoa_basep(unsigned int nbr, char *base);
int			ft_ptoa_basep(size_t nbr, char *base);
long int	ft_itoa_basep(long int nbr, char *base, int flag);
int			ft_utoa_baseh(unsigned int nbr, char *base);

/*---   EXEC.C   ---*/

void		exec_c(t_printf *p, char c);
void		exec_s(t_printf *p, char *str);
void		exec_p(t_printf *p, unsigned long long int nb);
void		exec_n(t_printf *p, int nb);
void		exec_u(t_printf *p, unsigned int nb);

/*---   EXEC2.C   ---*/

int			dot_printer(t_printf *p, int i, long int nb);
void		exec_x(t_printf *p, size_t nb);
void		exec_mx(t_printf *p, size_t nb);
void		exec_pr(t_printf *p);
void		print_nb(t_printf *p, int len);

/*---   BONUS.c   ---*/

void		bonus_printer(t_printf *p, char c);
long		minus_printer(t_printf *p, long nb, int flag);
void		print_nb2(t_printf *p, int len);
int			lflagsettern(t_printf *p, long nb, int lflag);
int			lflagsetteru(t_printf *p, unsigned int nb, int lflag);
int			lflagsetterx(t_printf *p, size_t nb, int lflag);
int			lflagsettermx(t_printf *p, size_t nb, int lflag);
int			lflagsetterp(t_printf *p, unsigned long long int nb, int lflag);

/*---   FT_PRINTF.C   ---*/

int			ft_printf(const char *str, ...);

#endif
