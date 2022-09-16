/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:50:24 by bammar            #+#    #+#             */
/*   Updated: 2022/09/16 18:07:27 by bammar           ###   ########.fr       */
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
	char	*temp;
	ssize_t	red;

	full = NULL;
	if (rest)
		full = ft_strdup(rest);
	red = read(fd, buf, BUFFER_SIZE);
	while (red > 0)
	{
		buf[red] = 0;
		if (full)
		{
			temp = full;
			full = ft_strjoin(full, buf);
			free(temp);
		}
		else
			full = ft_strdup(buf);
		if (get_index_of('\n', buf) != -1)
			break ;
		red = read(fd, buf, BUFFER_SIZE);
	}
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
	if (new_line_i == -1 || s[new_line_i + 1] == 0)
		return (NULL);
	str = ft_strdup(&(s[new_line_i + 1]));
	if (!str)
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
	if (rest)
		free(rest);
	line = get_line(full);
	rest = get_rest(full);
	if (line != full)
		free(full);
	if (!line)
		return (NULL);
	return (line);
}
