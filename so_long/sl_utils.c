/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:49:58 by bammar            #+#    #+#             */
/*   Updated: 2022/10/20 19:27:31 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_index	*new_index(int x, int y)
{
	t_index	*index;

	index = malloc(sizeof(t_index));
	if (!index)
		return (NULL);
	index->x = x;
	index->y = y;
	return (index);
}

char	*read_file(int fd)
{
	char	buf[BUFFER_SIZE + 1];
	char	*full;
	char	*temp;
	ssize_t	red;

	full = NULL;
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
		red = read(fd, buf, BUFFER_SIZE);
	}
	return (full);
}
