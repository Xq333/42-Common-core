/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:42:00 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/01/23 16:33:35 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

char	*ft_substr2(const char *s, unsigned int start, int len, char *buff)
{
	char	*s2;
	int		i;

	i = 0;
	if (len == 0 && ft_strchr(buff, '\n') == 0)
	{
		freeee((char *)s);
		return (0);
	}
	s2 = malloc ((sizeof(char) * (len + 1)));
	if (!s2)
		return (0);
	while (s && s[i + start] && i < len)
	{
		s2[i] = s[start + i];
		i++;
	}
	freeee((char *)s);
	s2[i] = 0;
	if (ft_strlen2(s2) == 0 && ft_strchr(buff, '\n') == 0)
	{
		freeee(s2);
		return (0);
	}
	return (s2);
}

char	*line_reader(int fd, char *line)
{
	int		b;
	char	*buff;

	buff = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	b = read(fd, buff, BUFFER_SIZE);
	if (b == 0 && ft_strlen2(line) == 0)
	{
		freeee(line);
		freeee(buff);
		return (0);
	}
	buff[b] = '\0';
	line = ft_strjoin(line, buff);
	while (line && ft_strchr(line, '\n') == 0 && b == BUFFER_SIZE)
	{
		b = read(fd, buff, BUFFER_SIZE);
		buff[b] = '\0';
		if (b != 0)
			line = ft_strjoin(line, buff);
	}
	if (ft_strchr(line, '\n') == 0)
		freeee(buff);
	return (line);
}

char	*line_parser(char *line, int diff, char *buff)
{
	int	diff2;

	diff2 = ft_strchr(line, '\n');
	line = ft_substr2(line, diff + 1, diff2, buff);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*line;
	int			i;
	int			diff;

	i = 0;
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd < 0)
	{
		free (line);
		return (0);
	}
	line = line_reader(fd, line);
	if (line == 0)
		return (0);
	diff = ft_strlen2(line) - ft_strchr(line, '\n');
	if (ft_strchr(line, '\n') == 0)
		buff = ft_substr(line, 0, diff);
	else
		buff = ft_substr(line, 0, diff + 1);
	line = line_parser(line, diff, buff);
	return (buff);
}
