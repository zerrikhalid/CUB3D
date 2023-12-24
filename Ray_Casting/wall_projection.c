/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_projection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 23:47:31 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/24 23:16:31 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	h_distance(t_player *player)
{
	player->is_vert = 0;
	player->wall_inter = player->hxhitwall;
	player->pd = player->h_distance
		* cos(d_to_r(player->rotationangle) - player->ray_angle);
	player->wallstripheight = (CUBE / player->pd) * player->distance_p_plane;
	player->topheight = (HEIGHT / 2) - (player->wallstripheight / 2);
	if (player->topheight < 0)
		player->topheight = 0;
	player->wallbottom = (HEIGHT / 2) + (player->wallstripheight / 2);
	if (player->wallbottom > HEIGHT)
		player->wallbottom = HEIGHT;
}

static void	v_distance(t_player *player)
{
	player->is_vert = 1;
	player->wall_inter = player->vyhitwall;
	player->pd = player->v_distance
		* cos(d_to_r(player->rotationangle) - player->ray_angle);
	player->wallstripheight = (CUBE / player->pd) * player->distance_p_plane;
	player->topheight = (HEIGHT / 2) - (player->wallstripheight / 2);
	if (player->topheight < 0)
		player->topheight = 0;
	player->wallbottom = (HEIGHT / 2) + (player->wallstripheight / 2);
	if (player->wallbottom > HEIGHT)
		player->wallbottom = HEIGHT;
}

void	wall_projection(t_player *player, int i)
{
	double			ytext;
	unsigned int	color;
	double			xtext;

	if (player->h_distance < player->v_distance)
		h_distance(player);
	else
		v_distance(player);
	player->path = check_wich_tx(player->paths, player);
	xtext = get_xtext(player->wall_inter, player->path);
	while (player->topheight < player->wallbottom && player->topheight < HEIGHT)
	{
		ytext = get_ytext(player->topheight, player->wallstripheight,
				player->path);
		color = get_texture_color(player->path, xtext, ytext);
		adjust_c(player->mlx->img, i, player->topheight, color);
		player->topheight++;
	}
}
