/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:27:17 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/18 22:39:52 by kzerri           ###   ########.fr       */
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
	if (!collision(player, next_x, next_y))
	{
		player->x += next_x;
		player->y += next_y;
	}
}
