/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:27:35 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/01/18 11:17:17 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort3(t_pswap *p)
{
	if (p->a->s->v < p->a->s->next->v && p->a->s->v < p->a->end->v)
	{
		if (p->a->end->v < p->a->s->next->v)
		{
			rra(p);
			sa(p);
		}
	}
	else if (p->a->s->next->v < p->a->s->v && p->a->s->next->v < p->a->end->v)
	{
		if (p->a->s->v < p->a->end->v)
			sa(p);
		else if (p->a->s->v > p->a->end->v)
			ra(p);
	}
	else if (p->a->end->v < p->a->s->v && p->a->end->v < p->a->s->next->v)
	{
		if (p->a->s->next->v < p->a->s->v)
		{
			ra(p);
			sa(p);
		}
		else if (p->a->s->next->v > p->a->s->v)
			rra(p);
	}
}

static void	firstsort(t_pswap *p)
{
	int	min;

	while (p->a->length > 3)
	{
		min = findminus(p->a);
		if (findclosest(p->a, min))
			while (p->a->s->v != min)
				rra(p);
		else
			while (p->a->s->v != min)
				ra(p);
		pb(p);
	}
	sort3(p);
	while (p->b)
		pa(p);
}

static void	sorting(t_pswap *p)
{
	int	stack;
	int	i;
	int	tmp;
	int	mediane;

	while (p->a)
	{
		tmp = p->a->length / 6;
		if (p->a->length < 250)
			tmp = p->a->length / 3;
		i = -1;
		stack = findstackmin(p->a, tmp);
		mediane = findstackmediane(p->a, tmp);
		while (i++ < tmp && p->a)
			sortpart1(p, stack, mediane);
	}
	while (p->b)
	{
		sortpart3(p);
	}
}

void	algorithm(t_pswap *p)
{
	if (p->a->length == 1)
		return ;
	if (p->a->length == 2)
	{
		if (p->a->end->v < p->a->s->v)
			sa(p);
	}
	else if (p->a->length == 3)
		sort3(p);
	else if (p->a->length < 40)
		firstsort(p);
	else
		sorting(p);
	ft_print_instruction("");
}
