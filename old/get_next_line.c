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

#include <fcntl.h> /*open*/
#include <stdio.h> /*printf*/

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char	*buf;
	int		n;
	int l;

	if (!fd || !*line || !line)
		return (-1);
	*line = 0;
	if (buf)
	{
		if((n = ft_strn(buf)) != - 1)
		{
			buf[n] = '\0';
			*line = ft_strjoin(*line, buf);
			if (buf[n + 1] != '\0')
				buf = &buf[n + 1];
			return (1);
		}
		*line = ft_strjoin(*line, buf);
	}
	else if(!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((l = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[l] = '\0';
		if((n = ft_strn(buf)) != - 1)
		{
			buf[n] = '\0';
			*line = ft_strjoin(*line, buf);
			buf = &buf[n + 1];
			break;
		}
		*line = ft_strjoin(*line, buf);
	}
	return ((!l) ? 0 : 1 );
}

int main()
{
	char	*line_buf;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	while(get_next_line(fd, &line_buf))
		printf("%s\n", line_buf);
	// get_next_line(fd, &line_buf);
	// printf("%s\n", line_buf);
	return (0);
}
