/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 20:33:10 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/06/22 14:01:50 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

void	exec_c(t_printf *p, char c)
{
	int	lflag;

	lflag = 0;
	if (p->nb)
		lflag = p->nb - 1;
	if (p->nb && p->minus == 0)
		print_nb(p, 1);
	if (lflag < 0)
		lflag = 0;
	write(1, &c, 1);
	if (p->nb && p->minus == 1)
		print_nb(p, 1);
	p->len += lflag + 1;
}

void	exec_s(t_printf *p, char *str)
{
	int	len;
	int	lflag;

	len = 0;
	lflag = 0;
	if (!str && p->prec > -1)
		str = "(null)";
	if (p->prec == -1)
		str = NULL;
	if (p->nb)
		lflag = p->nb - ft_strlen(str);
	if (p->nb && p->prec > 0)
		lflag = p->nb - (ft_strlen(str) - (ft_strlen(str) - p->prec));
	if (p->nb && p->prec > 0 && p->prec > (int)ft_strlen(str))
		lflag = p->nb - ft_strlen(str);
	if (lflag < 0)
		lflag = 0;
	if (p->nb && p->minus == 0)
		print_nb2(p, lflag);
	if (p->prec != -1)
		len += putstr(str, p);
	if (p->nb && p->minus == 1)
		print_nb2(p, lflag);
	p->len += len + lflag;
}

void	exec_p(t_printf *p, unsigned long long int nb)
{
	int	len;
	int	lflag;

	len = 0;
	lflag = 0;
	if (p->nb)
		lflag = p->nb - ft_ptoa_basep(nb, "0123456789abcdef") - 2;
	lflag = lflagsetterp(p, nb, lflag);
	if (p->nb && p->minus == 0)
		print_nb2(p, lflag);
	if (lflag < 0)
		lflag = 0;
	write(1, "0x", 2);
	if (p->prec != -1 || nb)
		len += ft_ptoa_base(nb, "0123456789abcdef");
	if (p->nb && p->minus == 1)
		print_nb2(p, lflag);
	p->len += len + lflag + 2;
}

void	exec_n(t_printf *p, int nbr)
{
	int		len;
	int		lflag;
	long	nb;

	len = 0;
	lflag = 0;
	nb = nbr;
	lflag = lflagsettern(p, nb, lflag);
	if (p->zero == 1 && p->nb && p->prec && p->nb > p->prec)
		p->zero = 0;
	if (p->plus == 1 && nb >= 0)
		bonus_printer(p, '+');
	if (p->space == 1 && nb >= 0)
		bonus_printer(p, ' ');
	if (p->nb && p->minus == 0)
		nb = minus_printer(p, nb, lflag);
	if (p->prec != -1 || nb)
		len += ft_itoa_base(nb, "0123456789", 0, p);
	if (p->nb && p->minus == 1)
		print_nb2(p, lflag);
	p->len += len + lflag;
}

void	exec_u(t_printf *p, unsigned int nb)
{
	int	len;
	int	lflag;

	len = 0;
	lflag = 0;
	lflag = lflagsetteru(p, nb, lflag);
	if (p->zero == 1 && p->nb && p->prec > 0 && p->nb > p->prec)
		p->zero = 0;
	if (p->nb && p->minus == 0)
		print_nb2(p, lflag);
	if (p->prec != -1 || nb)
		len += ft_utoa_base(nb, "0123456789", p);
	if (p->nb && p->minus == 1)
		print_nb2(p, lflag);
	p->len += len + lflag;
}
