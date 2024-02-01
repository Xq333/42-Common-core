/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 23:22:40 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/11/13 19:31:39 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	verif(char s1, char const *set)
{
	size_t	y;

	y = 0;
	while (set[y])
	{
		if (((char *)set)[y] == s1)
			return (1);
		y++;
	}
	return (0);
}

static size_t	counter(const char *s1, char const *set)
{
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	while (verif(s1[i], set) == 1 && s1[i])
	{
		i++;
		count++;
	}
	if (count == ft_strlen(s1))
		return (count);
	while (s1[i])
		i++;
	i--;
	while (verif(s1[i], set) == 1 && s1[i])
	{
		i--;
		count++;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	i;
	size_t	x;
	size_t	count;

	i = 0;
	x = 0;
	if ((char *)s1 == 0)
		return (ft_strdup(""));
	if (set == 0)
		return ((char *)s1);
	count = counter(s1, set);
	if (count == ft_strlen(s1))
		return (ft_strdup(""));
	s2 = malloc(sizeof(char) * ((ft_strlen(s1) - count) + 1));
	if (!s2)
		return (0);
	while (verif(s1[i], set) == 1 && s1[i])
		i++;
	while (x < (ft_strlen(s1) - count) && s1[i])
		(s2)[x++] = s1[i++];
	(s2)[x] = '\0';
	return (s2);
}
