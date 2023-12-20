/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:15:42 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/21 00:47:53 by kzerri           ###   ########.fr       */
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
				mlx_put_pixel(player->mlx->img, j, i, 0x612000FF);
			else
				mlx_put_pixel(player->mlx->img, j, i, 0x612000FF);
			j++;
		}
		i++;
	}
}
void	set_up_player(t_player *player, t_mlx *mlx)
{
	player->x = player->text->x * CUBE;
	player->y = player->text->y * CUBE;
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
	player->distance_p_plane = (WIDTH / 2) / tan(FOV / 2);
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
	player->mlx->img = mlx_new_image(player->mlx->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(player->mlx->mlx, player->mlx->img, 0, 0);
	floor_ceil(player);
	raycasting(player);
}
