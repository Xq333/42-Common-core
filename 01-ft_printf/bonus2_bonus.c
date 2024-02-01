/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:03:29 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/06/22 16:04:24 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"

int	lflagsetteru(t_printf *p, unsigned int nb, int lflag)
{
	if (p->nb)
		lflag = p->nb - ft_utoa_basep(nb, "0123456789");
	if (p->nb && p->prec > ft_utoa_basep(nb, "0123456789"))
		lflag = p->nb - (ft_utoa_basep(nb, "0123456789") \
			- (ft_utoa_basep(nb, "0123456789") - p->prec));
	if (p->prec == -1 && !nb)
		lflag = p->nb;
	if (lflag < 0)
		lflag = 0;
	return (lflag);
}

int	lflagsetterx(t_printf *p, size_t nb, int lflag)
{
	if (p->nb)
		lflag = p->nb - ft_utoa_basep(nb, "0123456789abcdef");
	if (p->nb && p->prec > ft_utoa_basep(nb, "0123456789abcdef"))
		lflag = p->nb - (ft_utoa_basep(nb, "0123456789abcdef") \
			- (ft_utoa_basep(nb, "0123456789abcdef") - p->prec));
	if (p->prec == -1 && !nb)
		lflag = p->nb;
	if (lflag < 0)
		lflag = 0;
	return (lflag);
}

int	lflagsettermx(t_printf *p, size_t nb, int lflag)
{
	if (p->nb)
		lflag = p->nb - ft_utoa_basep(nb, "0123456789ABCDEF");
	if (p->nb && p->prec > ft_utoa_basep(nb, "0123456789ABCDEF"))
		lflag = p->nb - (ft_utoa_basep(nb, "0123456789ABCDEF") \
			- (ft_utoa_basep(nb, "0123456789ABCDEF") - p->prec));
	if (p->prec == -1 && !nb)
		lflag = p->nb;
	if (lflag < 0)
		lflag = 0;
	return (lflag);
}
