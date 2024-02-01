/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 08:27:55 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/11/10 16:28:36 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (0);
	while (i < size - 1 && s1[i] == s2[i] && s2[i] && s1[i])
		i++;
	if (!(i < size) && s1[i - 1] == s2[i - 1])
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
