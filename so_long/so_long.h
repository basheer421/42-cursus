/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:04:36 by bammar            #+#    #+#             */
/*   Updated: 2022/11/01 16:42:19 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define RAT_IMAGE_YOFFSET -5

typedef enum key_map
{
	ON_DESTROY = 17,
	ESC = 53,
	KEY_UP = 126,
	KEY_DOWN = 125,
	KEY_RIGHT = 124,
	KEY_LEFT = 123,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2
}					t_key_map;

typedef struct s_mlx_vars
{
	void			*mlx_ptr;
	void			*win_ptr;
}					t_mlx_vars;

typedef struct s_image_vars
{
	void			*block;
	void			*wall;
	void			*rat;
	void			*exit;
	void			*cheese;
}					t_image_vars;

typedef struct s_index
{
	int				x;
	int				y;
}					t_index;

typedef struct s_map_vars
{
	int				exit_count;
	int				player_count;
	int				coin_count;
}					t_map_vars;

typedef struct s_map
{
	int				width;
	int				height;
	char			**map;
	t_index			*player_pos;
	t_map_vars		*map_vars;
}					t_map;

typedef struct s_hook_vars
{
	int				move_count;
	t_map			*map;
	t_image_vars	*image_vars;
	t_mlx_vars		*mlx_vars;
}					t_hook_vars;

t_map				*map_read(char *map_path);
int					map_check(t_map *map);
int					map_draw(t_mlx_vars *mlx_vars, t_map *map,
						t_image_vars *image_vars);
int					valid_path(t_map *map, t_index *index, int *visited,
						char end);
void				image_load(t_mlx_vars *mlx_vars, t_image_vars *image_vars);
t_index				*new_index(int x, int y);
int					safe_index(t_map *map, t_index *index);
char				*read_file(int fd);
void				map_free(t_map *map);
int					key_hook(int keycode, t_hook_vars *hook_vars);
int					sl_exit(t_hook_vars *hook_vars);

#endif