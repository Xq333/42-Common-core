/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_bonus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:03:16 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/01/18 13:02:27 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	pa(t_pswap *p)
{
	if (p->b && p->b->length > 0)
	{
		insert_values_fronta(p, p->b->s->v);
		del_values_frontb(p);
		p->moves++;
	}
}

void	pb(t_pswap *p)
{
	if (p->a && p->a->length > 0)
	{
		insert_values_frontb(p, p->a->s->v);
		del_values_fronta(p);
		p->moves++;
	}
}
