/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:28:38 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/06/22 13:58:26 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"

static void	setup(t_printf *p)
{
	p->htag = 0;
	p->len = 0;
	p->minus = 0;
	p->nb = 0;
	p->plus = 0;
	p->prec = 0;
	p->zero = 0;
	p->space = 0;
}

static void	resetup(t_printf *p)
{
	p->htag = 0;
	p->minus = 0;
	p->nb = 0;
	p->plus = 0;
	p->prec = 0;
	p->zero = 0;
	p->space = 0;
}

void	printer(t_printf *p, va_list va, char c)
{
	if (c == 'c')
		exec_c(p, va_arg(va, int));
	else if (c == 's')
		exec_s(p, va_arg(va, char *));
	else if (c == 'p')
		exec_p(p, va_arg(va, unsigned long long int));
	else if (c == 'd' || c == 'i')
		exec_n(p, va_arg(va, int));
	else if (c == 'u')
		exec_u(p, va_arg(va, unsigned int));
	else if (c == 'x')
		exec_x(p, va_arg(va, size_t));
	else if (c == 'X')
		exec_mx(p, va_arg(va, size_t));
	else if (c == '%')
		exec_pr(p);
}

int	percent(t_printf *p, va_list va, char *str, int i)
{
	i++;
	i = flags(p, str, i);
	printer(p, va, str[i++]);
	resetup(p);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	t_printf	p;
	int			i;
	va_list		va;

	va_start(va, str);
	if (!str)
		return (0);
	setup(&p);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			i = percent(&p, va, (char *)str, i);
		else
		{
			write(1, &str[i++], 1);
			p.len++;
		}
	}
	return (p.len);
}

/* #include <limits.h> */
/* int	main(void) */
/* { */
/* 	static char *s_hidden = "hi low\0don't print me lol\0"; */
/* 	printf("%d\n", ft_printf("%.0s", "hello")); */
/* 	printf("%d\n", printf("%.0s", "hello")); */
/* 	printf("%d\n", ft_printf("%7.5s", "bombastic")); */
/* 	printf("%d\n", printf("%7.5s", "bombastic")); */
/* 	printf("%d\n", ft_printf("%7.5s", "yolo")); */
/* 	printf("%d\n", printf("%7.5s", "yolo")); */
/* 	printf("%d\n", ft_printf("%-7.5s", "yolo")); */
/* 	printf("%d\n", printf("%-7.5s", "yolo")); */
/* 	printf("%d\n", ft_printf("%10.s", NULL)); */
/* 	printf("%d\n", printf("%10.s", NULL)); */
/* 	printf("%d\n", ft_printf("%23s", NULL)); */
/* 	printf("%d\n", printf("%23s", NULL)); */
/* 	printf("%d\n", ft_printf("%3.s", s_hidden)); */
/* 	printf("%d\n", printf("%3.s", s_hidden)); */
/* 	printf("%d\n", ft_printf("%8.5u", 34)); */
/* 	printf("%d\n", printf("%8.5u", 34)); */
/* 	printf("%d\n", ft_printf("%8.5i", 34)); */
/* 	printf("%d\n", printf("%8.5i", 34)); */
/* 	printf("%d\n", ft_printf("%10.5i", -216)); */
/* 	printf("%d\n", printf("%10.5i", -216)); */
/* 	printf("%d\n", ft_printf("%8.3i", 8375)); */
/* 	printf("%d\n", printf("%8.3i", 8375)); */
/* 	printf("%d\n", ft_printf("%08.5i", 34)); */
/* 	printf("%d\n", printf("%08.5i", 34)); */
/* 	printf("%d\n", ft_printf("%08.3i", -8473)); */
/* 	printf("%d\n", printf("%08.3i", -8473)); */
/* 	printf("%d\n", ft_printf("%.0i", 0)); */
/* 	printf("%d\n", printf("%.0i", 0)); */
/* 	printf("%d\n", ft_printf("%5.0i", 0)); */
/* 	printf("%d\n", printf("%5.0i", 0)); */
/* 	printf("%d\n", ft_printf("%.u", 0)); */
/* 	printf("%d\n", printf("%.u", 0)); */
/* 	printf("%d\n", ft_printf("%5.u", 0)); */
/* 	printf("%d\n", printf("%5.u", 0)); */
/* 	printf("%d\n", ft_printf("%08.5u", 34)); */
/* 	printf("%d\n", printf("%08.5u", 34)); */
/* 	printf("%d\n", ft_printf("%8.5x", 34)); */
/* 	printf("%d\n", printf("%8.5x", 34)); */
/* 	printf("%d\n", ft_printf("%8.5X", 34)); */
/* 	printf("%d\n", printf("%8.5X", 34)); */
/* 	printf("%d\n", ft_printf("%5.u", 1)); */
/* 	printf("%d\n", printf("%5.u", 1)); */
/* 	printf("%d\n", ft_printf("%.u", 1)); */
/* 	printf("%d\n", printf("%.u", 1)); */
/* 	printf("%d\n", ft_printf("%.p", NULL)); */
/* 	printf("%d\n", printf("%.p", NULL)); */
/* 	printf("%d\n", ft_printf("%5.p", NULL)); */
/* 	printf("%d\n", printf("%5.p", NULL)); */
/* 	printf("%d\n", ft_printf(" %-9p %-10p ", LONG_MIN, LONG_MAX)); */
/* 	printf("%d\n", printf(" %-9p %-10p ", LONG_MIN, LONG_MAX)); */
/* 	printf("%d\n", ft_printf("%20.5i", -1024)); */
/* 	printf("%d\n", printf("%20.5i", -1024)); */
	/* printf("%d\n", ft_printf("%013.i" ,-1488496170)); */
	/* printf("%d\n", printf("%013.i" ,-1488496170)); */
/* } */
