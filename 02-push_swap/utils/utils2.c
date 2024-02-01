/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:14:05 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/01/17 10:30:35 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	maxfirst(t_pswap *p)
{
	if (findindex(p->b, findmaxis(p->b)) >= p->b->length / 2)
		while (p->b->s->v != findmaxis(p->b))
			rrb(p);
	else
		while (p->b->s->v != findmaxis(p->b))
			rb(p);
}

int	findindex(t_stack p, int nb)
{
	int		index;
	t_elem	*tmp;

	index = 0;
	tmp = p->s;
	while (tmp && tmp->v != nb)
	{
		index++;
		tmp = tmp->next;
	}
	return (index);
}

int	findmaxis(t_stack p)
{
	int		rep;
	t_elem	*elem;

	rep = -2147483648;
	elem = p->s;
	while (elem)
	{
		if (elem->v > rep)
			rep = elem->v;
		elem = elem->next;
	}
	return (rep);
}

int	findnextmin(t_stack p, int rep)
{
	t_elem	*elem;
	int		rep2;

	rep2 = 2147483647;
	elem = p->s;
	while (elem)
	{
		if (elem->v < rep2 && elem->v > rep)
			rep2 = elem->v;
		elem = elem->next;
	}
	return (rep2);
}

int	findstackmin(t_stack p, int tmp)
{
	int	rep;
	int	i;

	rep = findminus(p);
	i = 0;
	while (i++ < tmp)
		rep = findnextmin(p, rep);
	return (rep);
}
