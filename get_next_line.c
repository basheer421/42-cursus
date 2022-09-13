/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:50:24 by bammar            #+#    #+#             */
/*   Updated: 2022/09/13 23:01:57 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static long long	get_index_of(int c, const char *str)
{
	long long	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*get_full(int fd, char *rest)
{
	char	buf[BUFFER_SIZE + 1];
	char	*full;

	full = NULL;
	if (rest)
	{
		full = ft_strdup(rest);
		rest = NULL;
	}
	while (read(fd, buf, BUFFER_SIZE) > 0)
	{
		buf[BUFFER_SIZE] = 0;
		if (full)
			full = ft_strjoin(full, buf);
		else
			full = ft_strdup(buf);
		if (get_index_of('\n', buf) != -1)
			break ;
	}
	rest = NULL;
	return (full);
}

char	*get_line(char *s)
{
	char		*str;
	long long	len;

	if (!s)
		return (NULL);
	len = get_index_of('\n', s);
	if (len == -1)
		return (s);
	str = ft_substr(s, 0, len + 1);
	if (!str)
		return (NULL);
	return (str);
}

char	*get_rest(char *s)
{
	long long	new_line_i;
	char		*str;

	if (!s)
		return (NULL);
	new_line_i = get_index_of('\n', s);
	if (new_line_i == -1)
		return (NULL);
	str = &(s[new_line_i + 1]);
	if (*s == 0)
		return (NULL);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*full;
	char		*line;
	static char	*rest;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	full = get_full(fd, rest);
	line = get_line(full);
	rest = get_rest(full);
	return (line);
}
