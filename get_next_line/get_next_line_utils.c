/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:00:59 by soyamagu          #+#    #+#             */
/*   Updated: 2025/12/29 20:40:32 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr_ptr(char const *s, size_t len)
{
	char	*new_str;

	if (!s)
		return (NULL);
	new_str = malloc(len + 1);
	if (!new_str)
		return (NULL);
	new_str[len] = '\0';
	ft_memcpy_gnl(new_str, s, len);
	return (new_str);
}

char	*ft_strjoin_ptr(char const *s1, char const *s2)
{
	char	*s3;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = (size_t)(ft_strchr_gnl(s1, '\0') - s1);
	s2_len = (size_t)(ft_strchr_gnl(s2, '\0') - s2);
	s3 = malloc(s1_len + s2_len + 1);
	if (!s3)
		return (NULL);
	s3[s1_len + s2_len] = '\0';
	ft_memcpy_gnl(s3, s1, s1_len);
	ft_memcpy_gnl(s3 + s1_len, s2, s2_len);
	return (s3);
}

void	*ft_calloc_gnl(size_t nmemb, size_t size)
{
	unsigned char	*s;
	size_t			i;

	i = 0;
	if (nmemb == 0 || size == 0)
	{
		s = malloc(0);
		if (!s)
			return (NULL);
		return (s);
	}
	s = malloc(size * nmemb);
	if (!s)
		return (NULL);
	while (i < size * nmemb)
	{
		s[i] = '\0';
		i++;
	}
	return ((void *)s);
}

void	*ft_memcpy_gnl(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return ((void *)d);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while ((const unsigned char)s[i] != '\0')
	{
		if ((const unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((const unsigned char)s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	return (NULL);
}
