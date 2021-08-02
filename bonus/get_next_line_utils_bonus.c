/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 01:26:44 by cdionna           #+#    #+#             */
/*   Updated: 2021/01/24 01:26:46 by cdionna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*line_join(char *dst, char *src, int len)
{
	int		i;
	int		j;
	char	*buf;

	i = 0;
	j = ft_strlen(dst) + len + 1;
	if (!(buf = (char *)malloc(j * sizeof(char))))
		return (NULL);
	while (dst[i] != '\0')
	{
		buf[i] = dst[i];
		i++;
	}
	free(dst);
	j = 0;
	while (src[j] != '\0' && len != j)
	{
		buf[i + j + 1] = '\0';
		buf[i + j] = src[j];
		j++;
	}
	return (buf);
}

int		ft_strn(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		++i;
	if (s[i] == '\n')
		return (i);
	return (-1);
}

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*dup;
	int		i;

	i = 0;
	if (!(dup = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char))))
		return (0);
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
