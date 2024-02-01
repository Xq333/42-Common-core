/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:21:07 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/01/18 11:23:49 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	ft_print_instruction(char *action)

{
	static char	*last_action;

	if (!last_action)
		last_action = ft_strdup(action);
	else
	{
		if ((!ft_strcmp(last_action, "sa") && !ft_strcmp(action, "sb"))
			|| (!ft_strcmp(last_action, "sb") && !ft_strcmp(action, "sa")))
			ft_printf("ss\n");
		else if ((!ft_strcmp(last_action, "ra") && !ft_strcmp(action, "rb"))
			|| (!ft_strcmp(last_action, "rb") && !ft_strcmp(action, "ra")))
			ft_printf("rr\n");
		else if ((!ft_strcmp(last_action, "rra") && !ft_strcmp(action, "rrb"))
			|| (!ft_strcmp(last_action, "rrb") && !ft_strcmp(action, "rra")))
			ft_printf("rrr\n");
		else
		{
			ft_printf("%s\n", last_action);
			if (ft_strcmp(action, ""))
				ft_printf("%s\n", action);
		}
		if (last_action)
			free(last_action);
		last_action = NULL;
	}
}

char	*ft_strdup(const char *s)
{
	void	*s2;

	s2 = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (s2 == 0)
		return (0);
	return ((char *) ft_memcpy(s2, s, ft_strlen(s) + 1));
}

void	*ft_memcpy(void *d, const void *s, size_t size)
{
	size_t	i;

	i = 0;
	if (!d && !s)
		return (NULL);
	while (i < size)
	{
		((char *)d)[i] = ((char *)s)[i];
		i++;
	}
	return (d);
}

void	sortpart3(t_pswap *p)
{
	int	max;
	int	nextmax;

	max = findmaxis(p->b);
	if (p->b->length > 1)
	{
		nextmax = findnextmaxis(p->b, max);
		if (findclosestn(p->b, max) > findclosestn(p->b, nextmax))
		{
			if (findindex(p->b, nextmax) >= p->b->length / 2)
				while (p->b->s->v < nextmax)
					rrb(p);
			else
				while (p->b->s->v < nextmax)
					rb(p);
			push(p);
		}
		else
		{
			maxfirst(p);
			pa(p);
		}
	}
	else
		pa(p);
}
