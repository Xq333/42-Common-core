/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:51:44 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/11/10 23:18:37 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		size;
	size_t		i;
	size_t		x;
	const char	*s3;

	i = -1;
	x = 0;
	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	size = ft_strlen(s1) + ft_strlen(s2);
	s3 = malloc (sizeof(char) * (size + 1));
	if (!s3)
		return (0);
	while (s1[++i] && x < size)
		((char *)s3)[x++] = s1[i];
	i = -1;
	while (s2[++i] && x < size)
		((char *)s3)[x++] = s2[i];
	((char *)s3)[x] = '\0';
	return ((char *)s3);
}
