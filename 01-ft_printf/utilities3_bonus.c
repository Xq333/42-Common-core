/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:31:59 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/06/09 16:18:19 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"

int	ft_utoa_basep(unsigned int nbr, char *base)
{
	char			str2[10000];	
	int				i;
	int				y;
	unsigned long	nb;

	nb = nbr;
	y = 0;
	if (nb == 0)
		y++;
	i = 0;
	while (nb > 0)
	{
		str2[i++] = base[nb % ft_strlen(base)];
		nb /= ft_strlen(base);
	}
	y += i;
	return (y);
}

long int	ft_itoa_basep(long int nbr, char *base, int flag)
{
	char	str2[10000];	
	int		i;
	long	nb;
	int		y;

	nb = nbr;
	y = 0;
	if (nb == 0)
		y++;
	i = 0;
	if (nb < 0 && flag == 0)
	{
		y++;
		nb *= -1;
	}
	while (nb > 0)
	{
		str2[i++] = base[nb % ft_strlen(base)];
		nb /= ft_strlen(base);
	}
	y += i;
	return (y);
}

int	ft_ptoa_basep(size_t nbr, char *base)
{
	char			str2[10000];	
	int				i;
	int				y;
	unsigned long	nb;

	nb = nbr;
	y = 0;
	if (nb == 0)
		y++;
	i = 0;
	while (nb > 0)
	{
		str2[i++] = base[nb % ft_strlen(base)];
		nb /= ft_strlen(base);
	}
	y += i;
	return (y);
}

int	ft_utoa_baseh(unsigned int nbr, char *base)
{
	char			str2[10000];	
	int				i;
	int				y;
	unsigned long	nb;

	nb = nbr;
	y = 0;
	if (nb == 0)
		y++;
	i = 0;
	while (nb > 0)
	{
		str2[i++] = base[nb % ft_strlen(base)];
		nb /= ft_strlen(base);
	}
	if ((str2[i - 1] && str2[i - 1] == '0' && i == 2) || nbr == 0)
		return (0);
	return (1);
}
