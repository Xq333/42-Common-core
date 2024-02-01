/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:42:00 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/02/15 12:10:03 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_substr2(const char *s, unsigned int start, int len, char *buff)
{
	char	*s2;
	int		i;

	i = 0;
	if (len == 0 && ft_strchr(buff, '\n') == 0)
	{
		freee((char *)s);
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
	freee((char *)s);
	s2[i] = 0;
	if (ft_strchr(buff, '\n') == 0 || ft_strlen(s2) == 0)
	{
		freee(s2);
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
	if (b == 0 && ft_strlen(line) == 0)
	{
		freee(line);
		freee(buff);
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
		freee(buff);
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
	static char	*line[4096];
	int			i;
	int			diff;

	i = 0;
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd < 0)
	{
		if (line[fd])
			freee(line[fd]);
		line[fd] = NULL;
		return (0);
	}
	line[fd] = line_reader(fd, line[fd]);
	if (line[fd] == 0)
		return (0);
	diff = ft_strlen(line[fd]) - ft_strchr(line[fd], '\n');
	if (ft_strchr(line[fd], '\n') == 0)
		buff = ft_substr(line[fd], 0, diff);
	else
		buff = ft_substr(line[fd], 0, diff + 1);
	line[fd] = line_parser(line[fd], diff, buff);
	return (buff);
}
