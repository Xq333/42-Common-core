/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:06:20 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/11/13 19:30:52 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	check(long n)
{
	long	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static long	ft_power(int i)
{
	long	rep;

	rep = 1;
	while (i-- > 1)
		rep *= 10;
	return (rep);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	int		i;
	char	c;

	nb = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	i = check(nb);
	while (i > 0)
	{
		c = (nb / ft_power(i)) + '0';
		ft_putchar_fd(c, fd);
		nb -= (nb / ft_power(i)) * ft_power(i);
		i--;
	}
}
