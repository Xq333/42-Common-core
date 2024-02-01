/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:29:45 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/11/12 10:35:29 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*rep;
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	rep = malloc (sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!rep)
		return (0);
	while (i < ft_strlen((char *)s))
	{
		rep[i] = (*f)(i, ((char *)s)[i]);
		i++;
	}
	rep[i] = 0;
	return (rep);
}
