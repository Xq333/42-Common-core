/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackmovesa_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:54:34 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/01/18 15:03:38 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	insert_values_backa(t_pswap *p, int nb)
{
	t_elem	*elem;

	elem = malloc(sizeof(*elem));
	if (!elem)
		printerror();
	elem->v = nb;
	elem->next = NULL;
	elem->previous = NULL;
	if (is_empty(p->a))
	{
		p->a = malloc(sizeof(*p->a));
		if (!p->a)
			printerror();
		p->a->length = 0;
		p->a->s = elem;
		p->a->end = elem;
	}
	else
	{
		p->a->end->next = elem;
		elem->previous = p->a->end;
		p->a->end = elem;
	}
	p->a->length++;
}

void	insert_values_fronta(t_pswap *p, int nb)
{
	t_elem	*elem;

	elem = malloc(sizeof(*elem));
	if (!elem)
		printerror();
	elem->v = nb;
	elem->next = NULL;
	elem->previous = NULL;
	if (is_empty(p->a))
	{
		p->a = malloc(sizeof(*p->a));
		if (!p->a)
			printerror();
		p->a->length = 0;
		p->a->s = elem;
		p->a->end = elem;
	}
	else
	{
		p->a->s->previous = elem;
		elem->next = p->a->s;
		p->a->s = elem;
	}
	p->a->length++;
}

void	del_values_fronta(t_pswap *p)
{
	t_elem	*tmp;

	if (is_empty(p->a))
	{
		newstack();
		return ;
	}
	if (p->a->s == p->a->end)
	{
		tmp = p->a->s;
		free(tmp);
		tmp = NULL;
		free(p->a);
		p->a = NULL;
		newstack();
		return ;
	}
	tmp = p->a->s;
	p->a->s = p->a->s->next;
	p->a->s->previous = NULL;
	tmp->next = NULL;
	tmp->previous = NULL;
	free(tmp);
	tmp = NULL;
	p->a->length--;
}

void	del_values_backa(t_pswap *p)
{
	t_elem	*tmp;

	if (is_empty(p->a))
	{
		return ;
	}
	if (p->a->s == p->a->end)
	{
		tmp = p->a->s;
		free(tmp);
		tmp = NULL;
		free(p->a);
		p->a = NULL;
		return ;
	}
	tmp = p->a->end;
	p->a->end = p->a->end->previous;
	p->a->end->next = NULL;
	tmp->next = NULL;
	tmp->previous = NULL;
	free(tmp);
	tmp = NULL;
	p->a->length--;
}
