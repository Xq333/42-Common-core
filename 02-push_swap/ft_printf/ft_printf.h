/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:02:25 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/01/17 12:46:29 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

//ft_printf_utils1.c
int		ft_strlen(const char *str);
int		ft_putstr_fd(char *s, int fd);
int		ft_putchar_fd(char c, int fd);
int		ft_printfarg(char c, va_list aptr);
int		ft_printfnbr(const char *str, va_list aptr, char *b);

//ft_printf_nbrb.c
int		ft_nbrb(long nbr, int fd, char *base);
int		ft_nbrp(unsigned long long int *nbr, int fd, char *base);
int		ft_unbrb(unsigned int nbr, int fd, char *base);
int		ft_nbrba(long nbr, int fd, char *base, char arg);

//ft_printf
int		ft_printf(const	char *str, ...);

#endif