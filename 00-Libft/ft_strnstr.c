/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 08:53:48 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/11/10 19:47:50 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t size)
{
	size_t	i;
	size_t	y;

	i = 0;
	if ((!s1 || !s2) && size == 0)
		return (NULL);
	if (s2[0] == '\0')
		return ((char *)s1);
	while (i < size && s1[i])
	{
		y = 0;
		while (s1[i + y] == s2[y] && i + y < size)
		{
			if (s2[y + 1] == '\0')
				return ((char *)s1 + i);
			y++;
		}
		i++;
	}
	return (NULL);
}
