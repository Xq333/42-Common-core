/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:54:43 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/06/09 16:42:39 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	y;
	int	rep;

	i = 0;
	y = 1;
	rep = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			y = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (rep == 214748364 && str[i] == 8 && y == -1)
			return (-2147483648);
		rep = (rep * 10) + (str[i++] - 48);
	}
	return (rep * y);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	ft_utoa_base(unsigned int nbr, char *base, t_printf *p)
{
	char			str2[10000];	
	int				i;
	int				y;
	unsigned long	nb;

	nb = nbr;
	y = 0;
	if (nb == 0)
	{
		y++;
		write(1, &base[0], 1);
	}
	i = 0;
	while (nb > 0)
	{
		str2[i++] = base[nb % ft_strlen(base)];
		nb /= ft_strlen(base);
	}
	y += i;
	y += dot_printer(p, i, nbr);
	while (i--)
		write(1, &str2[i], 1);
	return (y);
}

long int	ft_itoa_base(long int nbr, char *base, int flag, t_printf *p)
{
	char	str2[10000];	
	int		i;
	long	nb;
	int		y;

	nb = nbr;
	y = 0;
	if (nb == 0)
		write(1, &base[y++], 1);
	i = 0;
	if (nb < 0 && flag == 0 && ++y)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	while (nb > 0)
	{
		str2[i++] = base[nb % ft_strlen(base)];
		nb /= ft_strlen(base);
	}
	y += i;
	y += dot_printer(p, i, nbr);
	while (i--)
		write(1, &str2[i], 1);
	return (y);
}

char	*ft_strndup(char const *line, int start, int end)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * (end - start) + 1);
	if (!str)
		return (NULL);
	while (start != end && line[start])
	{
		str[i] = line[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
