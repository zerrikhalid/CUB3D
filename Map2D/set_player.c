/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:15:42 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/20 17:15:48 by kzerri           ###   ########.fr       */
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
	while (i < (HEIGHT * CUBE))
	{
		j = 0;
		while (j < (WIDTH * CUBE))
		{
			if (i < (HEIGHT * CUBE) / 2)
				mlx_put_pixel(player->mlx->img, j, i, 0x3DD5F0FF);
			else
				mlx_put_pixel(player->mlx->img, j, i, 0x8696A9FF);
			j++;
		}
		i++;
	}
}
void	set_up_player(t_player *player, t_mlx *mlx)
{
	player->x = WIDTH * CUBE / 2;
	player->y = HEIGHT * CUBE / 2;
	player->radius = 7.0;
	player->rotationAngle = 90;
	player->mlx = mlx;
	player->moveSpeed = 3;
	player->turndirection = 0;
	player->walkdirection = 0;
	player->sideDirection = 0;
	player->rotationSpeed = 1;
	player->distance_p_plane = ((WIDTH * CUBE) / 2) * tan(FOV / 2);
	floor_ceil(player);
	raycasting(player);
}  


void	move_player(void *par)
{
	t_player *player;

	player = par;
	if (player->sideDirection || player->turndirection)
		left_right(player);
	if (player->walkdirection || player->turndirection)
		up_down(player);
	mlx_delete_image(player->mlx->mlx, player->mlx->img);
	player->mlx->img = mlx_new_image(player->mlx->mlx, WIDTH * CUBE, HEIGHT * CUBE);
	mlx_image_to_window(player->mlx->mlx, player->mlx->img, 0, 0);
	floor_ceil(player);
	raycasting(player);
}
