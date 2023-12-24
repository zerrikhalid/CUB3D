/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_down.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:27:37 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/24 23:18:50 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	up_down(t_player *player)
{
	double	next_x;
	double	next_y;

	rotate(player);
	next_y = sin(d_to_r(player->rotationangle))
		* (player->movespeed * player->walkdirection);
	next_x = cos(d_to_r(player->rotationangle))
		* (player->movespeed * player->walkdirection);
	if (!collision(player, next_x + (player->x + 5), next_y + player->y)
		&& !collision(player, next_x + (player->x - 5), next_y + player->y)
		&& !collision(player, next_x + player->x, next_y + (player->y + 5))
		&& !collision(player, next_x + player->x, next_y + (player->y - 5)))
	{
		player->y += next_y;
		player->x += next_x;
	}
}
