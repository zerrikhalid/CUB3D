/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_A.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:27:17 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/13 20:08:32 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	key_a(t_player *player)
{
	double next_y;
	double next_x;

	next_x	= cos(d_to_r(player->rotationAngle) + PI / 2) * player->moveSpeed; 
	next_y  = sin(d_to_r(player->rotationAngle) + PI / 2) * player->moveSpeed; 
	if (!collision(player, -next_x, -next_y))
	{
		player->x -= next_x;
		player->y -= next_y; 
		create_2d_map(player->mlx, NULL);
		move_player(player, player->mlx);
	}
}
