/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:27:37 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/12 11:08:30 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_up(t_player *player)
{
	double next_x;
	double next_y;

	next_y = sin(player->rotationAngle) * player->moveSpeed;
	next_x = cos(player->rotationAngle) * player->moveSpeed;
	if (!collision(player, next_x, next_y))
	{
		player->y += next_y;
		player->x += next_x;
		create_2d_map(player->mlx, NULL);
		move_player(player, player->mlx);
	}
}
