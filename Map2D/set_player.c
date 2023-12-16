/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:15:42 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/16 19:38:57 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double d_to_r(double deg)
{
	return (deg * PI/180);
}

void	set_up_player(t_player *player, t_mlx *mlx)
{
	player->x = (WIDTH * CUBE) / 2;
	player->y = (HEIGHT * CUBE) / 2;
	player->radius = 7;
	player->rotationAngle = 90;
	player->mlx = mlx;
	player->moveSpeed = 3;
	player->rotationSpeed = 3;
	circle(player, mlx);
	raycasting(player);
}

void	move_player(t_player *player, t_mlx *mlx)
{
	player->mlx = mlx;
	circle(player, mlx);
	// line(mlx, player->x, player->y, player->x + (cos(d_to_r(player->rotationAngle)) * (CUBE)), player->y + (sin(d_to_r(player->rotationAngle)) * (CUBE)));
	raycasting(player);
}
