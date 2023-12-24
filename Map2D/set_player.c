/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:29:32 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/24 20:32:14 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	d_to_r(double deg)
{
	return (deg * PI/180);
}

void	floor_ceil(t_player *player)
{
	int i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (i < HEIGHT / 2)
				mlx_put_pixel(player->mlx->img, j, i, player->text->c_color);
			else
				mlx_put_pixel(player->mlx->img, j, i, player->text->f_color);
			j++;
		}
		i++;
	}
}
void	set_up_player(t_player *player, t_mlx *mlx)
{
	player->x = (player->text->x * CUBE) + 32;
	player->y = (player->text->y * CUBE) + 32;
	player->text->mapp_h *= CUBE;
	player->text->mapp_w *= CUBE;
	player->radius = 7.0;
	player->rotationAngle = player->text->ra;
	player->mlx = mlx;
	player->moveSpeed = 6;
	player->turndirection = 0;
	player->walkdirection = 0;
	player->sideDirection = 0;
	player->rotationSpeed = 1;
	player->stop_mouse = -1;
	player->distance_p_plane = (WIDTH / 2) / tan(FOV / 2);
	floor_ceil(player);
	raycasting(player);
}  


void	move_player(void *par)
{
	t_player *player;
	int			x;
	int			y;

	player = par;
	if (player->stop_mouse != 1)
		return ;
	if (player->sideDirection || player->turndirection)
		left_right(player);
	if (player->walkdirection || player->turndirection)
		up_down(player);
	mlx_get_mouse_pos(player->mlx->mlx, &x, &y);
	x -= WIDTH / 2;
	player->rotationAngle += (double)x / 10;
	mlx_set_mouse_pos(player->mlx->mlx, WIDTH / 2, HEIGHT / 2);
	mlx_set_cursor_mode(player->mlx->mlx, MLX_MOUSE_HIDDEN);
	mlx_delete_image(player->mlx->mlx, player->mlx->img);
	player->mlx->img = mlx_new_image(player->mlx->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(player->mlx->mlx, player->mlx->img, 0, 0);
	mlx_set_instance_depth(player->mlx->img->instances, 0);
	floor_ceil(player);
	raycasting(player);
}

