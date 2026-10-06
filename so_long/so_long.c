/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:55:34 by bammar            #+#    #+#             */
/*   Updated: 2022/11/05 18:15:11 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_exit(t_hook_vars *hook_vars)
{
	map_free(hook_vars->map);
	mlx_clear_window(hook_vars->mlx_vars->mlx_ptr,
		hook_vars->mlx_vars->win_ptr);
	mlx_destroy_window(hook_vars->mlx_vars->mlx_ptr,
		hook_vars->mlx_vars->win_ptr);
	mlx_destroy_image(hook_vars->mlx_vars->mlx_ptr,
		hook_vars->image_vars->block);
	mlx_destroy_image(hook_vars->mlx_vars->mlx_ptr,
		hook_vars->image_vars->wall);
	mlx_destroy_image(hook_vars->mlx_vars->mlx_ptr, hook_vars->image_vars->rat);
	mlx_destroy_image(hook_vars->mlx_vars->mlx_ptr,
		hook_vars->image_vars->cheese);
	exit(0);
}

static void	change_pos(t_hook_vars *hook_vars, int pathx, int pathy)
{
	t_index	*player_pos;
	t_index	*new_player_pos;
	t_map	*map;

	map = hook_vars->map;
	player_pos = map->player_pos;
	new_player_pos = new_index(player_pos->x + pathx, player_pos->y + pathy);
	if (safe_index(map, new_player_pos)
		&& map->map[new_player_pos->y][new_player_pos->x] != '1'
		&& (map->map[new_player_pos->y][new_player_pos->x] != 'E'))
	{
		if (map->map[new_player_pos->y][new_player_pos->x] == 'C')
			(map->map_vars->coin_count)--;
		map->map[player_pos->y][player_pos->x] = '0';
		map->map[new_player_pos->y][new_player_pos->x] = 'P';
		free(map->player_pos);
		map->player_pos = new_player_pos;
		ft_printf("Move count: %d\n", ++(hook_vars->move_count));
	}
	if ((map->map[new_player_pos->y][new_player_pos->x] == 'E')
		&& (map->map_vars->coin_count == 0))
	{
		ft_printf("Move count: %d\n", ++(hook_vars->move_count));
		sl_exit(hook_vars);
	}
}

int	key_hook(int keycode, t_hook_vars *hook_vars)
{
	if (keycode == ESC)
		sl_exit(hook_vars);
	if (keycode == KEY_UP || keycode == KEY_W)
		change_pos(hook_vars, 0, -1);
	if (keycode == KEY_DOWN || keycode == KEY_S)
		change_pos(hook_vars, 0, 1);
	if (keycode == KEY_RIGHT || keycode == KEY_D)
		change_pos(hook_vars, 1, 0);
	if (keycode == KEY_LEFT || keycode == KEY_A)
		change_pos(hook_vars, -1, 0);
	mlx_clear_window(hook_vars->mlx_vars->mlx_ptr,
		hook_vars->mlx_vars->win_ptr);
	map_draw(hook_vars->mlx_vars, hook_vars->map, hook_vars->image_vars);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx_vars		mlx_vars;
	t_image_vars	image_vars;
	t_map			*map;
	t_hook_vars		hook_vars;

	if (argc != 2)
		return (perror("Error\nArgument Count"), 1);
	map = map_read(argv[1]);
	if (!map)
		return (1);
	if (map_check(map) > 0)
		return (map_free(map), 1);
	hook_vars.map = map;
	mlx_vars.mlx_ptr = mlx_init();
	mlx_vars.win_ptr = mlx_new_window(mlx_vars.mlx_ptr, map->width * 64,
			map->height * 64, "Kitchen rat");
	image_load(&mlx_vars, &image_vars);
	map_draw(&mlx_vars, map, &image_vars);
	hook_vars.move_count = 0;
	hook_vars.image_vars = &image_vars;
	hook_vars.mlx_vars = &mlx_vars;
	mlx_hook(mlx_vars.win_ptr, ON_DESTROY, 0, sl_exit, &hook_vars);
	mlx_key_hook(mlx_vars.win_ptr, key_hook, &(hook_vars));
	mlx_loop(mlx_vars.mlx_ptr);
	sl_exit(&hook_vars);
}
