/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 08:24:43 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/11/10 20:32:56 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int			i;
	const char	*s2;
	const char	*rep;

	s2 = str;
	rep = 0;
	i = 0;
	if (c == 0)
		return ((char *)s2 + ft_strlen(s2));
	while (s2[i])
	{
		if (s2[i] == (char) c)
			rep = s2 + i;
		i++;
	}
	return ((char *)rep);
}
