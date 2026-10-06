/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:43:04 by bammar            #+#    #+#             */
/*   Updated: 2022/10/30 19:26:57 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_image(t_mlx_vars *mlx_vars, void *image, int width, int height)
{
	mlx_put_image_to_window(mlx_vars->mlx_ptr, mlx_vars->win_ptr, image,
		height * 64, width * 64);
}

int	map_draw(t_mlx_vars *mlx_vars, t_map *map, t_image_vars *image_vars)
{
	int	height;
	int	width;

	height = 0;
	while (height < map->height)
	{
		width = 0;
		while (width < map->width)
		{
			if (map->map[height][width] == '1')
				put_image(mlx_vars, image_vars->wall, height, width);
			else
				put_image(mlx_vars, image_vars->block, height, width);
			if (map->map[height][width] == 'E')
				put_image(mlx_vars, image_vars->exit, height, width);
			else if (map->map[height][width] == 'P')
				put_image(mlx_vars, image_vars->rat, height, width);
			else if (map->map[height][width] == 'C')
				put_image(mlx_vars, image_vars->cheese, height, width);
			width++;
		}
		height++;
	}
	return (0);
}
