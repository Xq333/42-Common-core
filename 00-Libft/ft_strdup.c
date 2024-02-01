/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:27:42 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/11/10 20:20:49 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	void	*s2;

	s2 = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (s2 == 0)
		return (0);
	return ((char *) ft_memcpy(s2, s, ft_strlen(s) + 1));
}
