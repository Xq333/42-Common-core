/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbrb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:11:09 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/11/29 11:11:46 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extra.h"

static int	verif_base(char *base)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (x < ft_strlen(base))
	{
		while (i < ft_strlen(base))
		{
			if (base[x] == base[i] && i != x)
				return (0);
			if (base[x] == '+' || base[x] == '-')
				return (0);
			i++;
		}
		i = 0;
		x++;
	}
	return (1);
}

int	ft_nbrb(long nbr, int fd, char *base)
{
	int			i;
	static char	arr[10000];
	int			temp;
	long		x;

	i = 0;
	x = 0;
	if (nbr == 0)
		return (ft_putchar_fd(base[0], fd));
	if (nbr < 0 && verif_base(base) == 1)
	{
		ft_putchar_fd('-', fd);
		nbr *= -1;
		x++;
	}
	while (nbr > 0 && verif_base(base) == 1)
	{
		temp = nbr % ft_strlen(base);
		arr[i++] = base[temp];
		nbr /= ft_strlen(base);
	}
	while (i-- > 0 && verif_base(base) == 1)
		x += ft_putchar_fd(arr[i], fd);
	return (x);
}

int	ft_nbrp(unsigned long long int *nbr, int fd, char *base)
{
	size_t					i;
	char					arr[16];
	int						temp;
	unsigned long long int	nb;

	i = 0;
	temp = 0;
	nb = (size_t)nbr;
	if (nb == 0)
		return (ft_putchar_fd(base[0], fd));
	while (nb > 0 && verif_base(base) == 1)
	{
		temp = nb % ft_strlen(base);
		arr[i++] = base[temp];
		nb /= ft_strlen(base);
	}
	temp = i;
	while (i-- > 0 && verif_base(base) == 1)
		ft_putchar_fd(arr[i], fd);
	return (temp);
}

int	ft_unbrb(unsigned int nbr, int fd, char *base)
{
	size_t			i;
	char			arr[10000];
	int				temp;
	unsigned long	nb;

	i = 0;
	temp = 0;
	nb = nbr;
	if (nb == 0)
		return (ft_putchar_fd(base[0], fd));
	while (nb > 0 && verif_base(base) == 1)
	{
		temp = nb % ft_strlen(base);
		arr[i++] = base[temp];
		nb /= ft_strlen(base);
	}
	temp = i;
	while (i-- > 0 && verif_base(base) == 1)
		ft_putchar_fd(arr[i], fd);
	return (temp);
}

int	ft_nbrba(long nbr, int fd, char *base, char arg)
{
	int			i;
	static char	arr[10000];
	int			temp;
	long		x;

	i = 0;
	x = 0;
	if (nbr == 0)
		return (ft_putstr_fd("+0", fd));
	if (nbr < 0)
	{
		x += ft_putchar_fd('-', fd);
		nbr *= -1;
	}
	else
		x += ft_putchar_fd(arg, 1);
	while (nbr > 0)
	{
		temp = nbr % ft_strlen(base);
		arr[i++] = base[temp];
		nbr /= ft_strlen(base);
	}
	while (i-- > 0 && verif_base(base) == 1)
		x += ft_putchar_fd(arr[i], fd);
	return (x);
}
