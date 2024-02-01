/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 09:58:46 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/12/06 17:49:50 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extra.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putchar_fd(char c, int fd)
{
	if ((unsigned char )c != 255)
		write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int		i;
	char	c;

	i = 0;
	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (s[i])
	{
		c = s[i];
		write(fd, &c, 1);
		i++;
	}
	return (i);
}

int	ft_printfarg(char c, va_list aptr)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(aptr, int), 1));
	else if (c == '%')
		return (ft_putchar_fd('%', 1));
	else if (c == 's')
		return (ft_putstr_fd(va_arg(aptr, char *), 1));
	else if (c == 'p')
	{
		ft_putstr_fd("0x", 1);
		return ((ft_nbrp(va_arg(aptr, void *), 1, "0123456789abcdef") + 2));
	}
	else if (c == 'd')
		return (ft_nbrb(va_arg(aptr, int), 1, "0123456789"));
	else if (c == 'i')
		return (ft_nbrb(va_arg(aptr, int), 1, "0123456789"));
	else if (c == 'u')
		return (ft_unbrb((int)va_arg(aptr, unsigned int), 1, "0123456789"));
	else if (c == 'x')
		return (ft_unbrb((size_t)va_arg(aptr, size_t), 1, "0123456789abcdef"));
	else if (c == 'X')
		return (ft_unbrb((size_t)va_arg(aptr, size_t), 1, "0123456789ABCDEF"));
	else
		return (ft_putchar_fd(c, 1));
}

int	ft_printfnbr(const char *str, va_list aptr, char *b)
{
	size_t	i;
	int		l;

	i = 0;
	l = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			if (str[i] && str[i + 1] && str[i] == '+'
				&& (str[i + 1] == 'd' || str[i + 1] == 'i'))
				l += ft_nbrba(va_arg(aptr, int), 1, b, '+') + (0 * ++i);
			else
				l += ft_printfarg(str[i], aptr);
		}
		else
			l += ft_putchar_fd(str[i], 1);
		i++;
	}
	return (l);
}
