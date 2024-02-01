/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackmovesb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:54:34 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/01/16 11:05:50 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	insert_values_backb(t_pswap *p, int nb)
{
	t_elem	*elem;

	elem = malloc(sizeof(*elem));
	if (!elem)
		printerror();
	elem->v = nb;
	elem->next = NULL;
	elem->previous = NULL;
	if (is_empty(p->b))
	{
		p->b = malloc(sizeof(*p->b));
		if (!p->b)
			printerror();
		p->b->length = 0;
		p->b->s = elem;
		p->b->end = elem;
	}
	else
	{
		p->b->end->next = elem;
		elem->previous = p->b->end;
		p->b->end = elem;
	}
	p->b->length++;
}

void	insert_values_frontb(t_pswap *p, int nb)
{
	t_elem	*elem;

	elem = malloc(sizeof(*elem));
	if (!elem)
		printerror();
	elem->v = nb;
	elem->next = NULL;
	elem->previous = NULL;
	if (is_empty(p->b))
	{
		p->b = malloc(sizeof(*p->b));
		if (!p->b)
			printerror();
		p->b->length = 0;
		p->b->s = elem;
		p->b->end = elem;
	}
	else
	{
		p->b->s->previous = elem;
		elem->next = p->b->s;
		p->b->s = elem;
	}
	p->b->length++;
}

void	del_values_frontb(t_pswap *p)
{
	t_elem	*tmp;

	if (is_empty(p->b))
	{
		newstack();
		return ;
	}
	if (p->b->s == p->b->end)
	{
		tmp = p->b->end;
		free(tmp);
		tmp = NULL;
		free(p->b);
		p->b = NULL;
		newstack();
		return ;
	}
	tmp = p->b->s;
	p->b->s = p->b->s->next;
	p->b->s->previous = NULL;
	tmp->next = NULL;
	tmp->previous = NULL;
	free(tmp);
	tmp = NULL;
	p->b->length--;
}

void	del_values_backb(t_pswap *p)
{
	t_elem	*tmp;

	if (is_empty(p->b))
	{
		newstack();
		return ;
	}
	if (p->b->s == p->b->end)
	{
		tmp = p->b->end;
		free(tmp);
		tmp = NULL;
		free(p->b);
		p->b = NULL;
		newstack();
		return ;
	}
	tmp = p->b->end;
	p->b->end = p->b->end->previous;
	p->b->end->next = NULL;
	tmp->next = NULL;
	tmp->previous = NULL;
	free(tmp);
	tmp = NULL;
	p->b->length--;
}
