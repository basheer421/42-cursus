/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:28:56 by bammar            #+#    #+#             */
/*   Updated: 2022/10/20 19:27:09 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	safe_index(t_map *map, t_index *index)
{
	if (index->x >= map->width)
		return (0);
	if (index->y >= map->height)
		return (0);
	if (index->x < 0)
		return (0);
	if (index->y < 0)
		return (0);
	return (1);
}

int	valid_path(t_map *map, t_index *index, int *visited, char end)
{
	if (visited == NULL || index == NULL)
		return (0);
	if (map->map[index->y][index->x] == end)
	{
		visited[(map->width * index->y) + index->x] = 1;
		return (free(index), 1);
	}
	if ((safe_index(map, index)) && (map->map[index->y][index->x] != '1')
		&& ((map->map[index->y][index->x] != 'E')) && (!visited[(map->width
				* index->y) + index->x]))
	{
		visited[(map->width * index->y) + index->x] = 1;
		if (valid_path(map, new_index(index->x, index->y + 1), visited, end)
			|| valid_path(map, new_index(index->x, index->y - 1), visited, end)
			|| valid_path(map, new_index(index->x - 1, index->y), visited, end)
			|| valid_path(map, new_index(index->x + 1, index->y), visited, end))
			return (free(index), 1);
	}
	return (free(index), 0);
}
