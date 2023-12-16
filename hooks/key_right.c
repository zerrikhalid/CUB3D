/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_right.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:27:35 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/16 18:27:53 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_right(t_player *player)
{
	player->rotationAngle += player->rotationSpeed;
	if (player->rotationAngle > 360)
		player->rotationAngle -= 360;
	if (player->rotationAngle < 0)
		player->rotationAngle += 360;
	create_2d_map(player->mlx, NULL);
	move_player(player, player->mlx);
} 
 