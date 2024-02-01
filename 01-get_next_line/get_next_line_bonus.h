/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:41:58 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/11/25 01:06:47 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

//GNL utils
char	*ft_strjoin(char *s1, char *s2);
void	freee(void *ptr);
int		ft_strlen(char *str);
int		ft_strchr(char *str, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);

//GNL
char	*get_next_line(int fd);
char	*line_reader(int fd, char *line);
char	*ft_substr2(const char *s, unsigned int start, int len, char *buff);
char	*line_parser(char *line, int diff, char *buff);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

#endif
