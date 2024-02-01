/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:11:15 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/01/29 16:07:38 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static int	verif2(const char *str)
{
	if (!str[1] && (str[0] == '-' || str[0] == '+'))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

static int	verif(const char *str)
{
	int	i;
	int	p;

	i = -1;
	p = 1;
	if (str[i + 1] && (str[i + 1] == '-' || str[i + 1] == '+'))
		i++;
	while (str[++i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
	}
	if (verif2(str))
		return (1);
	return (0);
}

long	ft_atol(const char *str)
{
	long	i;
	long	y;
	long	rep;

	i = 0;
	y = 1;
	rep = 0;
	if (verif(str))
		return (-2147483649);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			y = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		rep = rep * 10 + (str[i++] - 48);
	if ((rep * y) > 2147483647 || (rep * y) < -2147483648)
		return (-2147483649);
	return (rep * y);
}

void	printerror(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
