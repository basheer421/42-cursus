/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:22:24 by bammar            #+#    #+#             */
/*   Updated: 2022/11/01 18:37:50 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	invalid_boarder(t_map *map, t_index *index)
{
	if (map->width <= 1 || map->height <= 1
		|| (int)ft_strlen(map->map[index->y]) != map->width)
		return (perror("Error\nMap size error"), 1);
	if ((index->y == 0 || index->y == map->height - 1)
		&& map->map[index->y][index->x] != '1')
		return (perror("Error\nMap side error"), 2);
	if ((index->x == 0 || index->x == map->width - 1)
		&& map->map[index->y][index->x] != '1')
		return (perror("Error\nMap side error"), 3);
	return (0);
}

static int	invalid_var_count(t_map *map, t_index *index, t_map_vars *map_vars)
{
	if (map->map[index->y][index->x] == 'E')
		(map_vars->exit_count)++;
	else if (map->map[index->y][index->x] == 'P')
		(map_vars->player_count)++;
	else if (map->map[index->y][index->x] == 'C')
		(map_vars->coin_count)++;
	return (0);
}

static int	invalid_path(t_map *map, t_index *index)
{
	int	*empty_map;

	empty_map = ft_calloc(map->height * map->width, sizeof(int));
	if (!empty_map)
		return (1);
	if ((map->map[index->y][index->x] == 'C') && (!valid_path(map,
				new_index(index->x, index->y), empty_map, 'P')))
		return (free(empty_map), perror("Error\nNo valid path for the coin"),
			1);
	if ((map->map[index->y][index->x] == 'P') && (!valid_path(map,
				new_index(index->x, index->y), empty_map, 'E')))
		return (free(empty_map), perror("Error\nNo valid path for the exit"),
			1);
	return (free(empty_map), 0);
}

static t_map_vars	*new_map_vars(void)
{
	t_map_vars	*map_vars;

	map_vars = malloc(sizeof(t_map_vars));
	if (!map_vars)
		return (NULL);
	map_vars->exit_count = 0;
	map_vars->player_count = 0;
	map_vars->coin_count = 0;
	return (map_vars);
}

int	map_check(t_map *map)
{
	t_index		*index;
	t_map_vars	*map_vars;

	if (!map || map->height > 15 || map->width > 36)
		return (perror("Error\nInvalid map (Too big for screen)"), 1);
	map_vars = new_map_vars();
	if (!map_vars)
		return (2);
	index = new_index(-1, -1);
	if (!index)
		return (3);
	while (++index->y < map->height)
	{
		index->x = -1;
		while (++index->x < map->width)
			if (invalid_boarder(map, index) || invalid_var_count(map, index,
					map_vars) || invalid_path(map, index))
				return (free(index), free(map_vars), 1);
	}
	free(index);
	if (map_vars->exit_count != 1 || map_vars->player_count != 1)
		return (free(map_vars),
			perror("Error\nMap variable error"), 1);
	map->map_vars = map_vars;
	return (0);
}
