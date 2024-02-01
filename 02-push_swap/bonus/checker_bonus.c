/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:57:52 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/02/14 08:37:06 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_free(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		freeee(split[i++]);
	freeee(split);
}

static int	errorchecker(int argc, char **argv, int tmp, int x)
{
	int	i;

	i = tmp;
	if (x == 1)
		exit(1);
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
	checker(&p);
	return (0);
}
