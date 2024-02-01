/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:42:03 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/11/10 22:45:40 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	const char	*s2;
	size_t		i;

	if (!s)
		return (0);
	if ((size_t) start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		s2 = malloc ((sizeof(char) * (ft_strlen(s + start) + 1)));
	else
		s2 = malloc ((sizeof(char) * (len + 1)));
	i = 0;
	if (!s2)
		return (0);
	while (s[i + start] && i < len)
	{
		((char *)s2)[i] = s[start + i];
		i++;
	}
	((char *)s2)[i] = 0;
	return ((char *)s2);
}
