/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 20:35:29 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/06/22 11:56:03 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	dot_printer(t_printf *p, int i, long int nb)
{
	int	y;

	if (nb == 0)
		i++;
	y = i;
	while (i < p->prec)
	{
		i++;
		write(1, "0", 1);
	}
	return (i - y);
}

void	print_nb(t_printf *p, int len)
{
	if (p->nb)
	{
		if (p->zero == 1)
			while (p->nb - len++ > 0)
				write(1, "0", 1);
		else
			while (p->nb - len++ > 0)
				write(1, " ", 1);
	}
}

void	exec_x(t_printf *p, size_t nb)
{
	int	len;
	int	lflag;

	len = 0;
	lflag = 0;
	lflag = lflagsetterx(p, nb, lflag);
	if (p->zero == 1 && p->nb && p->prec > 0 && p->nb > p->prec)
		p->zero = 0;
	if (p->nb && p->minus == 0)
		print_nb2(p, lflag);
	if (p->htag == 1 && ft_utoa_baseh(nb, "0123456789abcdef"))
	{
		write(1, "0x", 2);
		lflag += 2;
	}
	if (p->prec != -1 || nb)
		len += ft_utoa_base(nb, "0123456789abcdef", p);
	if (p->nb && p->minus == 1)
		print_nb2(p, lflag);
	p->len += len + lflag;
}

void	exec_mx(t_printf *p, size_t nb)
{
	int	len;
	int	lflag;

	len = 0;
	lflag = 0;
	lflag = lflagsettermx(p, nb, lflag);
	if (p->zero == 1 && p->nb && p->prec > 0 && p->nb > p->prec)
		p->zero = 0;
	if (p->nb && p->minus == 0)
		print_nb2(p, lflag);
	if (p->htag == 1 && ft_utoa_baseh(nb, "0123456789ABCDEF"))
	{
		write(1, "0X", 2);
		lflag += 2;
	}
	if (p->prec != -1 || nb)
		len += ft_utoa_base(nb, "0123456789ABCDEF", p);
	if (p->nb && p->minus == 1)
		print_nb2(p, lflag);
	p->len += len + lflag;
}

void	exec_pr(t_printf *p)
{
	exec_c(p, '%');
}
