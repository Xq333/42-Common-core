/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:42:03 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/01/23 16:49:32 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		size;
	size_t		i;
	size_t		x;
	char		*s3;

	i = -1;
	x = 0;
	if (!s1)
		size = ft_strlen2(s2);
	else
		size = ft_strlen2(s1) + ft_strlen2(s2);
	s3 = malloc (sizeof(char) * (size + 1));
	if (!s3)
		return (0);
	while (s1 && s1[++i] && x < size)
		(s3)[x++] = s1[i];
	i = -1;
	while (s2 && s2[++i] && x < size)
		(s3)[x++] = s2[i];
	(s3)[x] = '\0';
	freeee(s1);
	if (!(ft_strchr(s3, '\n') == 0))
		freeee(s2);
	return (s3);
}

int	ft_strlen2(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	ft_strchr(char *str, int c)
{
	int	i;
	int	tmp;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char) c)
		{
			tmp = ft_strlen2(str) - i;
			return (tmp);
		}
		i++;
	}
	return (0);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char		*s2;
	size_t		i;

	i = 0;
	if (!s)
		return (0);
	else
		s2 = malloc ((sizeof(char) * (len + 1)));
	if (!s2)
		return (0);
	while (s[i + start] && i < len)
	{
		s2[i] = s[start + i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}

void	freeee(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}
