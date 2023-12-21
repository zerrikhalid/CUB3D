/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_down.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:27:37 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/21 23:14:52 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	up_down(t_player *player)
{
	double next_x;
	double next_y;

	rotate(player);
	next_y = sin(d_to_r(player->rotationAngle)) * (player->moveSpeed * player->walkdirection);
	next_x = cos(d_to_r(player->rotationAngle)) * (player->moveSpeed * player->walkdirection);
	if (!collision(player, next_x + (player->x + 5), next_y + player->y) && !collision(player, next_x + (player->x - 5), next_y + player->y)
	 && !collision(player, next_x + player->x, next_y + (player->y + 5)) && !collision(player, next_x + player->x, next_y + (player->y - 5)))
	{
		player->y += next_y;
		player->x += next_x;
	}
}
 