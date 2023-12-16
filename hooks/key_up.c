/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:27:37 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/13 20:09:22 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_up(t_player *player)
{
	double next_x;
	double next_y;

	next_y = sin(d_to_r(player->rotationAngle)) * player->moveSpeed;
	next_x = cos(d_to_r(player->rotationAngle)) * player->moveSpeed;
	if (!collision(player, next_x, next_y))
	{
		player->y += next_y;
		player->x += next_x;
		create_2d_map(player->mlx, NULL);
		move_player(player, player->mlx);
	}
}
 