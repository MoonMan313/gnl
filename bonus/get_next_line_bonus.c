/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 01:26:25 by cdionna           #+#    #+#             */
/*   Updated: 2021/01/24 01:26:27 by cdionna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		get_buf(char **buf, char **line, int is_in_buf)
{
	char		*tmp;
	int			n;

	if ((n = ft_strn(*buf)) != -1)
	{
		if (n != 0)
			*line = line_join(*line, *buf, n);
		tmp = ft_strdup(&(*buf)[n + 1]);
		free(*buf);
		*buf = ft_strdup(tmp);
		free(tmp);
		return (1);
	}
	*line = line_join(*line, *buf, ft_strlen(*buf));
	if (is_in_buf)
	{
		free(*buf);
		*buf = NULL;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*buf[1024];
	int			l;

	if (BUFFER_SIZE <= 0 || !line || read(fd, buf[fd], 0) < 0)
		return (-1);
	*line = ft_strdup("");
	if (buf[fd] && (get_buf(&buf[fd], line, 1)))
		return (1);
	if (!(buf[fd] = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((l = read(fd, buf[fd], BUFFER_SIZE)) > 0)
	{
		buf[fd][l] = '\0';
		if (get_buf(&buf[fd], line, 0))
			break ;
	}
	if (l == 0)
	{
		free(buf[fd]);
		buf[fd] = NULL;
	}
	return ((!l) ? 0 : 1);
}
