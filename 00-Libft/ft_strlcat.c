/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 08:04:39 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/11/10 20:36:28 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *d, const char *src, size_t size)
{
	size_t	y;
	size_t	i;

	y = 0;
	i = 0;
	if ((!d || !src) && size == 0)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	i = ft_strlen(d);
	if (i > size)
		return (ft_strlen(src) + size);
	while (i < size - 1 && src[y])
		d[i++] = src[y++];
	d[i] = '\0';
	return (i + ft_strlen(src + y));
}
