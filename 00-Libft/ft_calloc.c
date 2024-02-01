/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:12:51 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/11/10 16:28:01 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t c, size_t size)
{
	void	*m;

	if (size == 0 || c == 0)
		return (ft_calloc(1, 1));
	if (c * size / c != size)
		return (0);
	m = malloc(size * c);
	if (!(m))
		return (0);
	ft_bzero(m, c * size);
	return (m);
}
