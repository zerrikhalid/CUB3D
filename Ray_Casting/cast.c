/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:35:16 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/24 23:49:38 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	raycasting(t_player *player)
{
	int	i;

	player->ray_angle = d_to_r(player->rotationangle) - (player->fov / 2);
	i = -1;
	while (++i < NUM_RAYS)
	{
		player->ray_angle = ft_normalize(player);
		player->foundhwall = false;
		player->foundvwall = false;
		player->h_distance = xyhorizonral(player);
		player->v_distance = xyvertical(player);
		wall_projection(player, i);
		player->ray_angle += player->fov / NUM_RAYS;
	}
}
