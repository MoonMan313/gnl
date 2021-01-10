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

# define BUFFER_SIZE 3

int		ft_strn(char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		get_next_line(int fd, char **line);
char	*get_buf(char *g_buf, char **g_line);

#endif
