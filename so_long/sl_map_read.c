/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 23:15:27 by bammar            #+#    #+#             */
/*   Updated: 2022/11/01 17:53:55 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*map_open(const char *map_path)
{
	int		fd;
	char	*file;

	if (ft_strncmp(map_path + ft_strlen(map_path) - 4, ".ber", 4) != 0)
		return (perror("Error\nInvalid file name"), NULL);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (perror("Error\nInvalid file"), NULL);
	file = read_file(fd);
	if (!file)
		return (perror("Error\nInvalid file"), NULL);
	if (file[0] == '\n' || file[0] == '\0')
		return (perror("Error\nInvalid file"), free(file), NULL);
	close(fd);
	return (file);
}

static int	check_invalid_letter(char c)
{
	if (c == '0' || c == '1' || c == 'P' || c == 'C' || c == 'E')
		return (0);
	return (1);
}

static t_map	*map_init(char *map_path)
{
	t_map	*map;
	char	*file;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->height = 0;
	map->player_pos = 0;
	map->width = 0;
	map->map_vars = 0;
	file = map_open(map_path);
	if (!file)
		return (free(map), NULL);
	map->map = ft_split(file, '\n');
	if (!map->map)
		return (free(file), NULL);
	return (free(file), map);
}

t_map	*map_read(char *map_path)
{
	t_map	*map;

	map = map_init(map_path);
	if (!map)
		return (NULL);
	map->height = -1;
	while (map->map[++map->height])
	{
		map->width = -1;
		while (map->map[map->height][++map->width]
			&& map->map[map->height][map->width] != '\n')
		{
			if (check_invalid_letter(map->map[map->height][map->width]))
				return (perror("Error\nInvalid map"), map_free(map), NULL);
			if (map->map[map->height][map->width] == 'P')
				map->player_pos = new_index(map->width, map->height);
		}
	}
	return (map);
}

void	map_free(t_map *map)
{
	int	i;

	i = -1;
	if (!map)
		return ;
	while (map->map[++i])
		free(map->map[i]);
	if (map->map)
		free(map->map);
	if (map->player_pos)
		free(map->player_pos);
	if (map->map_vars)
		free(map->map_vars);
	free(map);
}
