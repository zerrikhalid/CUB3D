/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:27:21 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/15 17:39:03 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	key_d(t_player *player)
{
	double next_y; 
	double next_x;

	next_y = sin(d_to_r(player->rotationAngle) + PI / 2) * player->moveSpeed;
	next_x = cos(d_to_r(player->rotationAngle) + PI / 2) * player->moveSpeed;
	if (!collision(player, next_x, next_y))
	{
		player->y += next_y;
		player->x += next_x;
		create_2d_map(player->mlx, NULL);
		move_player(player, player->mlx);
	}
}
