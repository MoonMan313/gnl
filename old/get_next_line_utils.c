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
	while (s[i] && s[i] != '\n')
		++i;
	if (s[i] == '\n')
		return (i);
	return (- 1);
}

// char	*ft_strchr(const char *s)
// {
// 	int i;

// 	i = 0;
// 	while (s[i] && s[i] != '\n')
// 		++i;
// 	if (s[i] == '\n')
// 		return ((char *)(s + i));
// 	return ((char *)0);
// }

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buf;
	size_t	len;

	if (!s1 || *s1 == '\0')
		return (ft_strdup(s2));
	if (!s2 || *s2 == '\0')
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(buf = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	if (ft_strlcpy(buf, s1, len) && ft_strlcat(buf, s2, len + 1))
		return (buf);
	return (NULL);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			i;
	size_t			j;
	unsigned char	*p_d;
	unsigned char	*p_s;

	i = 0;
	j = 0;
	p_d = (unsigned char *)dst;
	p_s = (unsigned char *)src;
	while (p_d[i] != '\0' && i < dstsize)
		i++;
	while (p_s[j] != '\0' && (i + j + 1 < dstsize))
	{
		p_d[i + j + 1] = '\0';
		p_d[i + j] = p_s[j];
		j++;
	}
	return (ft_strlen(src) + i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t			i;
	unsigned char	*p_d;
	unsigned char	*p_s;

	i = 0;
	p_d = (unsigned char *)dst;
	p_s = (unsigned char *)src;
	if (!dst)
		return (0);
	if (p_s == p_d || dstsize == 0)
		return (ft_strlen(src));
	while (p_s[i] && i < (dstsize - 1))
	{
		p_d[i] = p_s[i];
		i++;
	}
	p_d[i] = '\0';
	return (ft_strlen(src));
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
	char *dup;

	dup = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!dup)
		return (0);
	return (ft_memcpy(dup, s1, ft_strlen(s1) + 1));
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *p_src;
	unsigned char *p_dst;

	p_src = (unsigned char *)src;
	p_dst = (unsigned char *)dst;
	if (!n || p_src == p_dst)
		return (dst);
	while (n--)
	{
		*p_dst = *p_src;
		p_dst++;
		p_src++;
	}
	return (dst);
}