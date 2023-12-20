/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_projection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 23:47:31 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/20 16:13:18 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void	wall_projection(t_player *player, int i)
{
	double topheight;
	double wallbottom;
	double pd;

	if (player->h_distance < player->v_distance)
	{
		pd = player->h_distance * cos( d_to_r(player->rotationAngle) - player->ray_angle);
		player->wallstripheight = (CUBE / pd) * player->distance_p_plane;
		topheight = ((HEIGHT * CUBE) / 2) - (player->wallstripheight / 2);
		if (topheight < 0)
			topheight = 0;
		wallbottom = ((HEIGHT * CUBE) / 2) + (player->wallstripheight / 2);
		if (wallbottom > (HEIGHT * CUBE))
			wallbottom = (HEIGHT * CUBE);
		player->mlx->color =  0x280137FF;
	}
	else
	{	
		pd = player->v_distance * cos(d_to_r(player->rotationAngle) - player->ray_angle);
		player->wallstripheight = (CUBE / pd) * player->distance_p_plane;
		topheight = ((HEIGHT * CUBE) / 2) - (player->wallstripheight / 2);
		if (topheight < 0)
			topheight = 0;
		wallbottom = ((HEIGHT * CUBE) / 2) + (player->wallstripheight / 2);
		if (wallbottom > (HEIGHT * CUBE))
			wallbottom = (HEIGHT * CUBE);
		player->mlx->color = 0x280137FF;
	}
	while (topheight <= wallbottom && topheight < (HEIGHT * CUBE))
	{
		mlx_put_pixel(player->mlx->img, i, topheight, player->mlx->color);
		topheight++;
	}
}
