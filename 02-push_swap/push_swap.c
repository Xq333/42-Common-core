/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:55:48 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/02/14 10:06:03 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

static void	is_sorted(char **argv, int i, int argc, int x)
{
	int	y;
	int	tmp;

	tmp = i;
	y = tmp;
	while (argv[tmp])
		tmp++;
	while (argv[i])
	{
		if (i > 0 && ft_atol(argv[i - 1]) != -2147483649
			&& ft_atol(argv[i]) > ft_atol(argv[i - 1]))
			y++;
		i++;
	}
	if (y == tmp - 1)
	{
		if (argc != x)
			ft_free(argv);
		exit(0);
	}
}

static int	errorchecker(int argc, char **argv, int tmp, int x)
{
	int	i;

	i = tmp;
	if (x == 1)
		exit(0);
	while (argv[i])
	{
		if (ft_atol(argv[i]) == -2147483649)
		{
			if (argc != x)
				ft_free(argv);
			printerror();
		}
		i++;
	}
	i = tmp;
	is_sorted(argv, i, argc, x);
	is_doublon(argv, argc, x);
	return (0);
}

int	main(int argc, char **argv)
{
	t_pswap	p;
	int		i;
	int		x;

	i = 1;
	x = argc;
	if (argc == 2)
	{
		i = 0;
		x = argc - 1;
		argv = ft_split(argv[1], ' ');
	}
	p.a = newstack();
	p.b = newstack();
	p.moves = 0;
	if (errorchecker(x, argv, i, argc))
		return (-1);
	while (argv[i])
		insert_values_backa(&p, ft_atol(argv[i++]));
	if (x != argc)
		ft_free(argv);
	algorithm(&p);
	while (p.a)
		del_values_fronta(&p);
	return (0);
}
