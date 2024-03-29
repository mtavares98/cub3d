/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:40:07 by mtavares          #+#    #+#             */
/*   Updated: 2023/04/16 21:17:57 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <math.h>
# include <dirent.h>
# include <mlx.h>
# include "mlx_int.h"
# include <printf_fd.h>
# include <allocs.h>
# include <str.h>

# define PI 3.14159265359
# define PI2 6.28318530718
# define FOV 60
# define FOV2 30
# define SIZE_X 64
# define SIZE_Y 64

typedef struct s_cub	t_cub;
typedef struct s_image	t_image;
typedef struct s_map	t_map;
typedef struct s_game	t_game;
typedef struct s_proj	t_proj;

struct	s_map
{
	char	**map;
	int		width;
	int		height;
};

struct	s_image
{
	t_img	*no_tex;
	t_img	*so_tex;
	t_img	*we_tex;
	t_img	*ea_tex;
	t_img	*chess;
	int		colors[2];
	char	order[5];
};

struct s_proj
{
	int		scale;
	int		widht;
	int		height;
	int		half_width;
	int		half_height;
	float	increment;
};

struct s_game
{
	float	player_angle;
	float	ray_angle;
	void	*white;
	void	*blue;
	void	*black;
	int		map_position;
	int		depht_of_field;
	int		player_speed;
	int		delay;
	int		fov_on;
	int		map_on;
	int		pause;
	int		lights;
	int		textures_on;
	t_img	*fov;
	t_img	*mmp;
	t_img	*mmbase;
	t_img	*mini;
	t_img	*mpause;
};

struct s_cub
{
	void	*mlx;
	void	*mlx_win;
	char	**file;
	int		width;
	int		height;
	char	direction;
	float	px;
	float	py;
	int		num_player;
	int		side;
	t_img	*screen;
	t_image	img;
	t_map	map;
	t_game	game;
	t_proj	projection;
};

// INIT
void	init_vars(t_cub *cub);
void	init_img(t_cub *cub);
void	init_textutes(t_cub *cub, char **path);

// RENDER
int		render(t_cub *cub);

// MINIMAP
void	init_mini_map(t_cub *cub);
void	mini_map(t_cub *cub);

// FOV
void	init_fov(t_cub *cub);
void	draw_fov(t_cub *cub, int x, int y, int color);
void	clear_fov(t_cub *cub);
void	T_fov(t_cub *cub);

// KEYPRESS
int		key_press(int keycode, t_cub *game);
int		key_release(int keycode, t_cub *game);
void	press_w(float pCos, float pSin, t_cub *cub);
void	press_a(t_cub *cub);
void	press_d(t_cub *cub);
void	press_s(float pCos, float pSin, t_cub *cub);
int		mouse_hook(int button, int x, int y, t_cub *cub);

// RAYCAST
void	raycast(t_cub *cub);
void	draw_walls(t_cub *cub, int ray, float ray_angle, float ray_x, float ray_y);

// DRAW
void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color);
int		my_mlx_pixel_get(t_img *texture, int x, int y);
void	draw_square(t_cub *cub, int x, int y, int color);
void	draw_vertical_line(float x, float y, float len, t_cub *cub, int color);
void	draw_texture(int x, int y, float len, t_cub *cub, float WallX, float ray_x, float ray_y);
void	draw_texture2(int x, int y, float len, t_cub *cub, float WallX, t_img *texture, float ray_x);
void	get_pixel(t_cub *cub, int x, int y);
void	clear_screen(t_cub *cub);

// MATH FUNCTIONS
int		ft_abs(int n);

// UTILS
int		ft_exit(t_cub *game);
float	degrees_to_radians(float degrees);
int		fix_angle(int angle);
float	distance_between_points(float x1, float y1, float x2, float y2);
void	*ft_memset(void *str, int c, size_t n);

t_cub	*this_cub(void);
void	exit_free(t_cub *data, int status, char *str);
char	**parse(t_cub *data, char *name);
int		prep_alg(t_cub *data);
int		valid_chars(char c);
int		orientation_player(char c);
int		check_map(t_cub *data, char **path);

#endif
