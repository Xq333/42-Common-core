/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:03:19 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/01/17 13:42:43 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_pswap *p)
{
	int		tmp;

	tmp = 0;
	if (p->a && p->a->length > 1)
	{
		tmp = p->a->s->v;
		del_values_fronta(p);
		insert_values_backa(p, tmp);
		ft_print_instruction("ra");
		p->moves++;
	}
}

void	rb(t_pswap *p)
{
	int		tmp;

	tmp = 0;
	if (p->b && p->b->length > 1)
	{
		tmp = p->b->s->v;
		del_values_frontb(p);
		insert_values_backb(p, tmp);
		ft_print_instruction("rb");
		p->moves++;
	}
}
