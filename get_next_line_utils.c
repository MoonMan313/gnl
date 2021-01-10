/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 15:34:33 by cdionna           #+#    #+#             */
/*   Updated: 2020/11/28 15:34:36 by cdionna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buf;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 || *s1 == '\0')
		return (ft_strdup(s2));
	if (!s2 || *s2 == '\0')
		return (ft_strdup(s1));
	j = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!s1 || !s2 || !(buf = (char *)malloc(j * sizeof(char))))
		return (NULL);
	while (j != i)
	{
		j--;
		while(s1[i])
		{
			buf[i] = s1[i];
			i++;
		}
		buf[j] = s2[j -i];
	}
	return (buf);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!dup)
		return (0);
	while(s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
