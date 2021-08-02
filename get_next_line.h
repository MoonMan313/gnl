/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 15:34:49 by cdionna           #+#    #+#             */
/*   Updated: 2020/11/28 15:34:51 by cdionna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int		get_next_line(int fd, char **line);
int		get_buf(char **g_buf, char **g_line, int is_in_buf);

char	*line_join(char *dst, char *src, int len);
int		ft_strn(char *s);
int		ft_strlen(char *s);
char	*ft_strdup(char *s1);

#endif
