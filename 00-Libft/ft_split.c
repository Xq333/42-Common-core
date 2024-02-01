/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 02:00:45 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/11/13 19:31:13 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	split_counter(char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			i++;
			count++;
		}
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c && s[i])
			i++;
	}
	return (count);
}

static char	*ft_splitdup(char *s, size_t start, size_t end)
{
	char	*s2;
	size_t	i;

	i = 0;
	s2 = malloc (sizeof(char) * ((end - start) + 1));
	if (!s2)
		return (NULL);
	while (start + i < end)
	{
		s2[i] = s[start + i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}

static char	**freee(char **s2, size_t x)
{
	while (x -- > 0)
		free(s2[x]);
	free(s2);
	return (NULL);
}

static char	**ft_split2(char *s, char c, char **s2)
{
	size_t	start;
	size_t	x;
	size_t	i;

	i = 0;
	x = 0;
	start = 0;
	while (((char *)s)[i])
	{
		if (((char *)s)[i] != c && ((char *)s)[i])
			start = i++;
		while (((char *)s)[i] != c && ((char *)s)[i])
			i++;
		if (i != start && ((char *)s)[i - 1])
		{
			s2[x] = ft_splitdup(s, start, i);
			if (!s2[x])
				return (freee(s2, x));
			x++;
		}
		while (((char *)s)[i] == c && ((char *)s)[i])
			i++;
	}
	s2[x] = 0;
	return (s2);
}

char	**ft_split(const char *s, char c)
{
	char	**s2;

	if (s == 0)
		return (0);
	s2 = malloc (sizeof(char *) * (split_counter((char *)s, c) + 1));
	if (!s2)
		return (0);
	s2 = ft_split2((char *)s, c, s2);
	return (s2);
}
