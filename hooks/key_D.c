/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:27:21 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/12 10:48:27 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	key_d(t_player *player)
{
	double next_y;
	double next_x;

	next_y = sin(player->rotationAngle + PI/2) * player->moveSpeed;
	next_x = cos(player->rotationAngle + PI/2) * player->moveSpeed;
	if (!collision(player, next_x, next_y))
	{
		player->y += next_y;
		player->x += next_x;
		create_2d_map(player->mlx, NULL);
		move_player(player, player->mlx);
	}
}
