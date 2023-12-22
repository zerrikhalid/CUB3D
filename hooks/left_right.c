/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:27:17 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/22 03:24:16 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	left_right(t_player *player)
{
	double	next_y;
	double	next_x;

	rotate(player);
	next_x = cos(d_to_r(player->rotationAngle) + PI / 2) * (player->moveSpeed * player->sideDirection);
	next_y = sin(d_to_r(player->rotationAngle) + PI / 2) * (player->moveSpeed * player->sideDirection);
	if (!collision(player, next_x + (player->x + 5), next_y + player->y) && !collision(player, next_x + (player->x - 5), next_y + player->y)
	 && !collision(player, next_x + player->x, next_y + (player->y + 5))&& !collision(player, next_x + player->x, next_y + (player->y - 5)))
	{
		player->y += next_y;
		player->x += next_x;
	}
}
