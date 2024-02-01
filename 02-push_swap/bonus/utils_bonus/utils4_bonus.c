/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:02:38 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/02/14 08:45:57 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static int	reader(t_pswap *p, char *str)
{
	if (ft_strcmp(str, "ra\n") == 0)
		return (free(str), ra(p), 1);
	else if (ft_strcmp(str, "rb\n") == 0)
		return (free(str), rb(p), 1);
	else if (ft_strcmp(str, "rr\n") == 0)
		return (free(str), rr(p), 1);
	else if (ft_strcmp(str, "sa\n") == 0)
		return (free(str), sa(p), 1);
	else if (ft_strcmp(str, "sb\n") == 0)
		return (free(str), sb(p), 1);
	else if (ft_strcmp(str, "ss\n") == 0)
		return (free(str), ss(p), 1);
	else if (ft_strcmp(str, "rra\n") == 0)
		return (free(str), rra(p), 1);
	else if (ft_strcmp(str, "rrb\n") == 0)
		return (free(str), rrb(p), 1);
	else if (ft_strcmp(str, "rrr\n") == 0)
		return (free(str), rrr(p), 1);
	else if (ft_strcmp(str, "pa\n") == 0)
		return (free(str), pa(p), 1);
	else if (ft_strcmp(str, "pb\n") == 0)
		return (free(str), pb(p), 1);
	else
		return (0);
}

static void	clear(t_pswap *p)
{
	while (p->a)
		del_values_fronta(p);
	while (p->b)
		del_values_frontb(p);
}

static int	sorted(t_pswap *p)
{
	t_elem	*elem;
	int		y;

	elem = p->a->s;
	y = 0;
	while (elem)
	{
		if (elem->next && elem->next->v > elem->v)
			y++;
		elem = elem->next;
	}
	if (y == p->a->length - 1)
		return (1);
	return (0);
}

void	checker(t_pswap *p)
{
	char	*str;

	str = get_next_line(0);
	while (str && reader(p, str))
		str = get_next_line(0);
	if (!str)
	{
		if (p->b)
			write(1, "KO\n", 3);
		else if (!p->b && sorted(p))
			write(1, "OK\n", 3);
		else if (!p->b && !sorted(p))
			write(1, "KO\n", 3);
		clear(p);
		freeee(str);
	}
	else
	{
		clear(p);
		freeee(str);
		printerror();
	}
}
