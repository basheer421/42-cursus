/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_image_load.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:16:40 by bammar            #+#    #+#             */
/*   Updated: 2022/11/01 15:17:03 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_load(t_mlx_vars *mlx_vars, t_image_vars *image_vars)
{
	int	width;
	int	height;

	width = 64;
	height = 64;
	image_vars->block = mlx_xpm_file_to_image(mlx_vars->mlx_ptr,
			"assets/block3_64x64.xpm", &width, &height);
	image_vars->wall = mlx_xpm_file_to_image(mlx_vars->mlx_ptr,
			"assets/block4_64x64.xpm", &width, &height);
	image_vars->rat = mlx_xpm_file_to_image(mlx_vars->mlx_ptr,
			"assets/tile001.xpm", &width, &height);
	image_vars->cheese = mlx_xpm_file_to_image(mlx_vars->mlx_ptr,
			"assets/cheese.xpm", &width, &height);
	image_vars->exit = mlx_xpm_file_to_image(mlx_vars->mlx_ptr,
			"assets/exit.xpm", &width, &height);
}
