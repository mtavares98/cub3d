/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 01:57:37 by marvin            #+#    #+#             */
/*   Updated: 2023/02/18 01:57:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_img(t_img *img)
{
	if (!img)
		exit_free(this_cub(), 1, "Error allocating imgs");
}

void	init_textutes(t_cub *cub, char **path)
{
	int	img_width;
	int	img_height;

	cub->img.no_tex = mlx_xpm_file_to_image(cub->mlx, path[0], \
		&img_width, &img_height);
	check_img(cub->img.no_tex);
	cub->img.so_tex = mlx_xpm_file_to_image(cub->mlx, path[1], \
		&img_width, &img_height);
	check_img(cub->img.so_tex);
	cub->img.we_tex = mlx_xpm_file_to_image(cub->mlx, path[2], \
		&img_width, &img_height);
	check_img(cub->img.we_tex);
	cub->img.ea_tex = mlx_xpm_file_to_image(cub->mlx, path[3], \
		&img_width, &img_height);
	check_img(cub->img.ea_tex);
	cub->img.chess = mlx_xpm_file_to_image(cub->mlx, "textures/chess.xpm", \
		&img_width, &img_height);
	check_img(cub->img.chess);
}

void	init_img(t_cub *cub)
{
	int	img_width;
	int	img_height;

	cub->game.white = mlx_xpm_file_to_image(cub->mlx, "image/white.xpm", \
		&img_width, &img_height);
	check_img(cub->game.white);
	cub->game.blue = mlx_xpm_file_to_image(cub->mlx, "image/blue.xpm", \
		&img_width, &img_height);
	check_img(cub->game.blue);
	cub->game.black = mlx_xpm_file_to_image(cub->mlx, "image/black.xpm", \
		&img_width, &img_height);
	check_img(cub->game.black);
	cub->game.mpause = mlx_xpm_file_to_image(cub->mlx, "image/menu_pause.xpm", \
		&img_width, &img_height);
	check_img(cub->game.mpause);
	cub->game.mmp = mlx_new_image(cub->mlx, 5, 5);
	check_img(cub->game.mmp);
	ft_memset(cub->game.mmp->data, 150, cub->game.mmp->width * cub->game.mmp->height * sizeof(int));
	cub->screen = mlx_new_image(cub->mlx, cub->width, cub->height);
	check_img(cub->screen);
	ft_memset(cub->screen->data, 0, cub->screen->width * cub->screen->height * sizeof(int));
	cub->game.fov = mlx_new_image(cub->mlx, cub->map.width, cub->map.height);
	check_img(cub->game.fov);
	ft_memset(cub->game.fov->data, 0, cub->game.fov->width * cub->game.fov->height * sizeof(int));
	cub->game.mmbase = mlx_new_image(cub->mlx, cub->map.width - 16, cub->map.height);
	check_img(cub->game.mmbase);
	ft_memset(cub->game.mmbase->data, 0, (cub->game.mmbase->width - 16) * (cub->game.mmbase->height) * sizeof(int));
	cub->game.mini = mlx_new_image(cub->mlx, 128, 128);
	check_img(cub->game.mini);
	ft_memset(cub->game.mini->data, 0, cub->game.mini->width * cub->game.mini->height * sizeof(int));
}
