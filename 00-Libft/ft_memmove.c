/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:28:29 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/11/10 17:10:37 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *d, const void *s, size_t size)
{
	unsigned char	*s2;
	unsigned char	*d2;

	s2 = (unsigned char *)s;
	d2 = (unsigned char *)d;
	if (!d && !s)
		return (0);
	if (d2 < s2)
	{
		while (size--)
			*d2++ = *s2++;
	}
	else
	{
		d2 = d2 + size - 1;
		s2 = s2 + size - 1;
		while (size--)
			*d2-- = *s2--;
	}
	return (d);
}
