/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:15:42 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/12 10:43:28 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_up_player(t_player *player, t_mlx *mlx)
{
	player->x = (WIDTH * CUBE) / 2;
	player->y = (HEIGHT * CUBE) / 2;
	player->radius = 7;
	player->rotationAngle = PI / 2;
	player->mlx = mlx;
	player->moveSpeed = 5;
	player->rotationSpeed = 5 * (PI / 180);
	circle(player, mlx);
	line(mlx, player->x, player->y, player->x + (cos(player->rotationAngle) * (CUBE / 2)), player->y + (sin(player->rotationAngle) * (CUBE / 2)));
}

void	move_player(t_player *player, t_mlx *mlx)
{
	player->mlx = mlx;
	circle(player, mlx);
	line(mlx, player->x, player->y, player->x + (cos(player->rotationAngle) * (CUBE / 2)), player->y + (sin(player->rotationAngle) * (CUBE / 2)));
}
