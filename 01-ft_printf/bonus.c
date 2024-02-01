/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:53:52 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/06/22 16:05:04 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"

void	bonus_printer(t_printf *p, char c)
{
	p->nb--;
	p->len++;
	write(1, &c, 1);
}

long	minus_printer(t_printf *p, long nb, int flag)
{
	if (p->zero == 1 && nb < 0)
	{
		bonus_printer(p, '-');
		nb *= -1;
	}
	print_nb2(p, flag);
	return (nb);
}

void	print_nb2(t_printf *p, int len)
{
	if (p->nb)
	{
		if (p->zero == 1)
			while (len--)
				write(1, "0", 1);
		else
			while (len--)
				write(1, " ", 1);
	}
}

int	lflagsettern(t_printf *p, long nb, int lflag)
{
	if (p->nb)
		lflag = p->nb - ft_itoa_basep(nb, "0123456789", 0);
	if (p->nb && p->prec > ft_itoa_basep(nb, "0123456789", 0))
		lflag = p->nb - (ft_itoa_basep(nb, "0123456789", 0) \
			- (ft_itoa_basep(nb, "0123456789", 0) - p->prec));
	if (nb < 0 && p->nb && p->prec >= ft_itoa_basep(nb, "0123456789", 0))
		lflag--;
	if (p->prec == -1 && !nb)
		lflag = p->nb;
	if (lflag < 0)
		lflag = 0;
	return (lflag);
}

int	lflagsetterp(t_printf *p, unsigned long long int nb, int lflag)
{
	ft_ptoa_basep(nb, "0123456789abcdef");
	if (p->nb)
		lflag = p->nb - ft_ptoa_basep(nb, "0123456789abcdef");
	if (p->nb && p->prec > ft_ptoa_basep(nb, "0123456789abcdef"))
		lflag = p->nb - (ft_ptoa_basep(nb, "0123456789abcdef") \
			- (ft_ptoa_basep(nb, "0123456789abcdef") - p->prec));
	if (p->prec == -1 && !nb)
		lflag = p->nb;
	lflag -= 2;
	if (lflag < 0)
		lflag = 0;
	return (lflag);
}
