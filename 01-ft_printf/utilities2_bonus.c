/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 20:30:01 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/06/16 19:49:50 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"

int	ft_ptoa_base(size_t nbr, char *base)
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
	while (i--)
		write(1, &str2[i], 1);
	return (y);
}

int	isflag(char c)
{
	if (c == ' ' || (c >= '0' && c <= '9') || c == '+'
		|| c == '-' || c == '.' || c == '#')
		return (1);
	return (0);
}

int	getlen(char *str, int i, t_printf *p, char c)
{
	char	*tmp;
	int		start;

	if (str[i] == '.')
		i++;
	start = i;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	tmp = ft_strndup(str, start, i);
	if (c == '.')
	{
		p->prec = ft_atoi(tmp);
		if (str[i - 1] && !(str[i - 1] >= '0' && str[i - 1] <= '9'))
			p->prec = -1;
		if (p->prec == 0)
			p->prec = -1;
	}
	else
		p->nb = ft_atoi(tmp);
	free(tmp);
	return (i);
}

int	flags(t_printf *p, char *str, int i)
{
	while (isflag(str[i]))
	{
		if (str[i] == '+' && i++ > -1)
			p->plus = 1;
		if (str[i] == '-' && i++ > -1 && p->zero == 0)
			p->minus = 1;
		if (str[i] == ' ' && i++ > -1)
			p->space = 1;
		if (str[i] == '#' && i++ > -1)
			p->htag = 1;
		if (str[i] == '0' && i++ > -1 && p->minus == 0)
			p->zero = 1;
		if (str[i] == '.')
			i = getlen(str, i, p, '.');
		if (str[i] >= '0' && str[i] <= '9' && str[i] != '0')
			i = getlen(str, i, p, 'n');
	}
	return (i);
}

int	putstr(char *str, t_printf *p)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (p->prec > 0 && i >= p->prec)
			break ;
		write(1, &str[i], 1);
		i++;
	}
	len += i;
	return (len);
}
