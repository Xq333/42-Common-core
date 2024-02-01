/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:03:23 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/01/17 13:42:51 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_pswap *p)
{
	int	tmp;

	tmp = 0;
	if (p->a && p->a->length > 1)
	{
		tmp = p->a->s->v;
		p->a->s->v = p->a->s->next->v;
		p->a->s->next->v = tmp;
		ft_print_instruction("sa");
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
		ft_print_instruction("sb");
		p->moves++;
	}
}
