/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:28:58 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/19 19:59:59 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int matrix3[12][16] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
		{1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
		{1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

static void	find_wall(t_player *player)
{
	while (player->vXnext >= 0 && player->vXnext <= (WIDTH * CUBE) &&
		player->vYnext >= 0 && player->vYnext <= (HEIGHT * CUBE))
	{
		if (isleft(player))
			player->pivot = 1;
		if (matrix3[(int)player->vYnext / 64][(int)(player->vXnext - player->pivot) / 64] == 1)
		{
			player->foundVWall = true;
			player->vXhitwall = player->vXnext;
			player->vYhitwall = player->vYnext;
			break ;
		}
		player->vXnext += player->vxstep;
		player->vYnext += player->vystep;
	}
}

double xyVertical(t_player *player)
{
	player->vXintercept = floor(player->x / CUBE) * CUBE;
	if (isright(player))
		player->vXintercept += CUBE;
	player->vYintercept = player->y + ((player->vXintercept - player->x) * tan(player->ray_angle));
	player->vxstep = CUBE;
	if (isleft(player))
		player->vxstep *= -1;
	player->vystep = CUBE * tan(player->ray_angle);
	if (isup(player) && player->vystep > 0)
		player->vystep *= -1;
	if (isdown(player) && player->vystep < 0)
		player->vystep *= -1;
	player->vXnext = player->vXintercept;
	player->vYnext = player->vYintercept;
	player->pivot = 0;
	find_wall(player);
	if (player->foundVWall)
		return (distance(player, 1));
	return (INT_MAX);
}
