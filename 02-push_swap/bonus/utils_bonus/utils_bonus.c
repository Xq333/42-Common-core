/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:22:31 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/01/25 14:49:13 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	is_doublon(char **argv, int argc, int x)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[j])
		{
			if (ft_atol(argv[j]) == ft_atol(argv[i]) && i != j)
			{
				if (x != argc)
					free(argv);
				printerror();
			}
			j++;
		}
		i++;
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strdup(const char *s)
{
	void	*s2;

	s2 = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (s2 == 0)
		return (0);
	return ((char *) ft_memcpy(s2, s, ft_strlen(s) + 1));
}

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

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
