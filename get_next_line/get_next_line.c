/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 03:47:22 by soyamagu          #+#    #+#             */
/*   Updated: 2025/12/29 21:35:13 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*split_keep(char **keep);
static char	*eof_error_handling(int read_ret, char **keep);
static char	*gen_src(char *keep, void *buf);
static char	*free_ret(void *alloc_memory, char *return_value);

char	*get_next_line(int fd)
{
	static char	*keep;
	void		*buf;
	int			read_ret;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	read_ret = 1;
	if (keep && ft_strchr_gnl(keep, '\n'))
		return (split_keep(&keep));
	while (read_ret > 0)
	{
		buf = ft_calloc_gnl((BUFFER_SIZE + 1), sizeof(char));
		if (!buf)
			return (NULL);
		read_ret = read(fd, buf, BUFFER_SIZE);
		if (read_ret <= 0 && !(ft_strchr_gnl(keep, '\n')))
			return (free_ret(buf, eof_error_handling(read_ret, &keep)));
		keep = gen_src(keep, buf);
		if (!keep)
			return (free_ret(buf, NULL));
		if (ft_strchr_gnl(keep, '\n'))
			return (free_ret(buf, split_keep(&keep)));
		free (buf);
	}
	return (NULL);
}

static char	*split_keep(char **keep)
{
	char	*line;
	char	*old_keep;
	char	*newline;
	char	*ptr_null;

	old_keep = *keep;
	newline = ft_strchr_gnl(*keep, '\n');
	ptr_null = ft_strchr_gnl(*keep, '\0');
	line = ft_substr_ptr(*keep, (size_t)(newline - *keep) + 1);
	if (!line)
		return (free_ret(old_keep, NULL));
	if (ptr_null - (newline + 1) > 0)
	{
		*keep = ft_substr_ptr(newline + 1, (size_t)(ptr_null - newline));
		if (!keep)
			return (free_ret(old_keep, NULL));
	}
	else
		*keep = NULL;
	return (free_ret(old_keep, line));
}

static char	*eof_error_handling(int read_ret, char **keep)
{
	char	*old_keep;
	char	*ptr_null;
	char	*line;

	old_keep = *keep;
	ptr_null = ft_strchr_gnl(*keep, '\0');
	if (read_ret < 0)
	{
		*keep = NULL;
		return (free_ret(old_keep, NULL));
	}
	line = ft_substr_ptr(*keep, (size_t)(ptr_null - *keep) + 1);
	if (!line)
		return (free_ret(old_keep, NULL));
	*keep = NULL;
	return (free_ret(old_keep, line));
}

static char	*gen_src(char *keep, void *buf)
{
	char	*new_str;
	char	*end;
	char	*buf_data;
	char	*old_keep;

	if ((!keep && !buf) || !buf)
		return (NULL);
	buf_data = (char *)buf;
	if (!keep)
	{
		end = ft_strchr_gnl(buf_data, '\0');
		new_str = malloc((end - buf_data) + 1);
		if (!new_str)
			return (NULL);
		ft_memcpy_gnl(new_str, buf_data, (end - buf_data) + 1);
	}
	else
	{
		old_keep = keep;
		new_str = ft_strjoin_ptr(keep, buf_data);
		if (!new_str)
			return (NULL);
		free(old_keep);
	}
	return (new_str);
}

static char	*free_ret(void *alloc_memory, char *ret_value)
{
	if (!alloc_memory)
		return (NULL);
	free(alloc_memory);
	return (ret_value);
}
