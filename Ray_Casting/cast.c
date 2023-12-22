/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:35:16 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/21 20:48:37 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	raycasting(t_player *player)
{
	int		i;

	player->ray_angle = d_to_r(player->rotationAngle) - (FOV / 2);
	i = -1;
	while (++i < NUM_RAYS)
	{
		player->ray_angle = ft_normalize(player);
		player->foundHWall = false;
		player->foundVWall = false;
		player->h_distance = xyhorizonral(player);
		player->v_distance = xyVertical(player);
		wall_projection(player, i);
		player->ray_angle += FOV / NUM_RAYS;
	}
}
