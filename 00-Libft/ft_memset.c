/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:00:49 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/11/07 14:42:13 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void	*p, int v, size_t count)
{
	size_t	i;
	char	*p2;

	i = 0;
	p2 = (char *) p;
	while (i < count)
	{
		p2[i] = (char) v;
		i++;
	}
	return (p2);
}
