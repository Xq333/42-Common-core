/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:54:54 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/01/18 11:20:01 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	findclosest(t_stack p, int tmp)
{
	int		i1;
	int		i2;
	t_elem	*p1;
	t_elem	*p2;

	i1 = 0;
	i2 = 0;
	p1 = p->s;
	p2 = p->end;
	while (p2->v > tmp)
	{
		i2++;
		p2 = p2->previous;
	}
	while (p1->v > tmp)
	{
		i1++;
		p1 = p1->next;
	}
	if (i1 >= i2)
		return (1);
	return (0);
}

int	findnextmaxis(t_stack p, int rep)
{
	t_elem	*elem;
	int		rep2;

	rep2 = -2147483648;
	elem = p->s;
	while (elem)
	{
		if (elem->v > rep2 && elem->v < rep)
			rep2 = elem->v;
		elem = elem->next;
	}
	return (rep2);
}

void	sortpart1(t_pswap *p, int stack, int mediane)
{
	if (findclosest(p->a, stack))
		while (p->a->s->v > stack)
			rra(p);
	else
		while (p->a->s->v > stack)
			ra(p);
	if (p->a->s->v > mediane)
		pb(p);
	else
	{
		pb(p);
		rb(p);
	}
}

int	findstackmediane(t_stack p, int tmp)
{
	int	rep;
	int	i;

	rep = findminus(p);
	i = 0;
	while (i++ < tmp / 2 - 1)
		rep = findnextmin(p, rep);
	return (rep);
}

int	findclosestn(t_stack p, int tmp)
{
	int		i1;
	int		i2;
	t_elem	*p1;
	t_elem	*p2;

	i1 = 0;
	i2 = 0;
	p1 = p->s;
	p2 = p->end;
	while (p2->v < tmp)
	{
		i2++;
		p2 = p2->previous;
	}
	while (p1->v < tmp)
	{
		i1++;
		p1 = p1->next;
	}
	if (i1 >= i2)
		return (i2);
	return (i1);
}
