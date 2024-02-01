/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_bonus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:03:23 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/01/18 13:01:22 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	sa(t_pswap *p)
{
	int	tmp;

	tmp = 0;
	if (p->a && p->a->length > 1)
	{
		tmp = p->a->s->v;
		p->a->s->v = p->a->s->next->v;
		p->a->s->next->v = tmp;
		p->moves++;
	}
}

void	sb(t_pswap *p)
{
	int	tmp;

	tmp = 0;
	if (p->b && p->b->length > 1)
	{
		tmp = p->b->s->v;
		p->b->s->v = p->b->s->next->v;
		p->b->s->next->v = tmp;
		p->moves++;
	}
}

void	ss(t_pswap *p)
{
	sa(p);
	sb(p);
}
