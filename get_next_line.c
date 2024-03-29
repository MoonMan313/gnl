/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 15:34:16 by cdionna           #+#    #+#             */
/*   Updated: 2020/11/28 15:34:19 by cdionna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*buf;
	int			l;

	if (BUFFER_SIZE <= 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	*line = ft_strdup("");
	if (buf && (get_buf(&buf, line, 1)))
		return (1);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((l = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[l] = '\0';
		if (get_buf(&buf, line, 0))
			break ;
	}
	if (l == 0)
	{
		free(buf);
		buf = NULL;
	}
	return ((!l) ? 0 : 1);
}
