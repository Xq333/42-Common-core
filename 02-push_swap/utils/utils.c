/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:58:04 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/02/14 09:59:21 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	findminus(t_stack p)
{
	int		rep;
	t_elem	*elem;

	rep = 2147483647;
	elem = p->s;
	while (elem)
	{
		if (elem->v < rep)
			rep = elem->v;
		elem = elem->next;
	}
	return (rep);
}

static int	verif2(const char *str)
{
	if (!str[1] && (str[0] == '-' || str[0] == '+'))
		return (1);
	return (0);
}

static int	verif(const char *str)
{
	int	i;

	i = -1;
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
