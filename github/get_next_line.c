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

char	*get_buf(char *g_buf, char **g_line)
{
	int		n;
		if((n = ft_strn(g_buf)) != - 1)
		{
			g_buf[n] = '\0';
			*g_line = ft_strjoin(*g_line, g_buf);
			g_buf = &g_buf[n + 1];
			return (g_buf);			
		}
		*g_line = ft_strjoin(*g_line, g_buf);
		return(NULL);
}

int		get_next_line(int fd, char **line)
{
	static char	*buf;
	int		n;
	int l;

	if (fd < 0|| BUFFER_SIZE <= 0 || !line)
		return (-1);
	*line = 0;
	if (buf && (buf = get_buf(buf, line)))
			return (1);
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
	return ((!l) ? 0 : 1);
}

int main()
{
	char	*line_buf;
	int		fd;

	line_buf = "qwertyui fg";
	fd = open("test.txt", O_RDONLY);
	while(get_next_line(fd, &line_buf))
		printf("%s\n", line_buf);
		//  printf("\n");
	// printf("%d\n", get_next_line(fd, &line_buf));
	// printf("%s\n", line_buf);
	return (0);
}
