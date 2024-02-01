/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 08:43:31 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/11/13 19:30:31 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	mcount(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n >= 10 && i++ >= 0)
		n /= 10;
	return (i + 1);
}

char	*ft_itoa(int n)
{
	char	*rep;
	int		i;
	long	nb;

	nb = n;
	i = mcount(nb);
	rep = malloc(sizeof(char) * (i + 1));
	if (!rep)
		return (0);
	if (nb < 0)
		nb *= -1;
	rep [i--] = '\0';
	while (i >= 0)
	{
		rep[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		rep[0] = '-';
	return (rep);
}
/*
int	main(void)
{
	printf("%s\n", ft_itoa(-8124));
	return (0);
}
*/