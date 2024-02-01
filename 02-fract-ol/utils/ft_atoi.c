/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:28:42 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/12/22 16:47:16 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	atoierrorprinter(void)
{
	ft_printf("Error: available fractals:\n");
	ft_printf("./fract-ol Mandelbrot\n");
	ft_printf("./fract-ol Julia {option1} {option2}\n");
	ft_printf("./fract-ol Burningship\n");
	ft_printf("options must be doubles\n");
	return (1);
}

static long double	power(int x)
{
	return (pow(10, -x));
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
		{
			if (str[i] == '.' && p)
				p--;
			else
			{
				atoierrorprinter();
				return (1);
			}
		}
	}
	return (0);
}

long double	ft_atoi(const char *str)
{
	int			i;
	int			x;
	long double	y;
	long double	rep;

	i = 0.;
	y = 1.;
	x = 1;
	rep = 0.;
	if (verif(str))
		exit(1);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			y = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		rep = (rep * 10) + (str[i++] - 48);
	if (str[i++] == '.')
		while (str[i] >= '0' && str[i] <= '9')
			rep += (str[i++] - 48.0) * power(x++);
	return (rep * y);
}
