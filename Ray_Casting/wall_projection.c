/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_projection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 23:47:31 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/22 01:46:24 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	wall_projection(t_player *player, int i)
{
	double topheight;
	double wallbottom;
	double pd;
	double	ytext;
	unsigned int		color;
	double	xtext;

	if (player->h_distance < player->v_distance)
	{
		player->is_vert = 0;
		player->wall_inter = player->hXhitwall;
		pd = player->h_distance * cos( d_to_r(player->rotationAngle) - player->ray_angle);
		player->wallstripheight = (CUBE / pd) * player->distance_p_plane;
		topheight = (HEIGHT / 2) - (player->wallstripheight / 2);
		if (topheight < 0)
			topheight = 0;
		wallbottom = (HEIGHT / 2) + (player->wallstripheight / 2);
		if (wallbottom > HEIGHT)
			wallbottom = HEIGHT;
	}
	else
	{
		player->is_vert = 1;
		player->wall_inter = player->vYhitwall;
		pd = player->v_distance * cos(d_to_r(player->rotationAngle) - player->ray_angle);
		player->wallstripheight = (CUBE / pd) * player->distance_p_plane;
		topheight = (HEIGHT / 2) - (player->wallstripheight / 2);
		if (topheight < 0)
			topheight = 0;
		wallbottom = (HEIGHT / 2) + (player->wallstripheight / 2);
		if (wallbottom > HEIGHT)
			wallbottom = HEIGHT;
	}
	check_wich_tx(player->paths, player, &xtext);
	while (topheight <= wallbottom && topheight < HEIGHT)
	{
		check_wich_ty(player->paths, player, topheight, &ytext);
		color = get_texture_color(player, player->paths, xtext, ytext);
		adjust_c(player->mlx->img, i, topheight, color);
		topheight++;
	}
}
