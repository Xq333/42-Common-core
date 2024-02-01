/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 07:00:31 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/11/10 16:19:23 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
