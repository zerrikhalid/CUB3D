

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:28:45 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/19 19:54:24 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	find_wall(t_player *player)
{
	while (player->hXnext >= 0 && player->hXnext <= (WIDTH * CUBE) &&
		player->hYnext >= 0 && player->hYnext <= (HEIGHT * CUBE))
	{
		if (isup(player))
			player->pivot = 1;
		if (player->text->mapp[(int)(player->hYnext - player->pivot)/ 64][(int)player->hXnext / 64] == '1')
		{
			player->foundHWall = true;
			player->hXhitwall = player->hXnext;
			player->hYhitwall = player->hYnext;
			break ;
		}
		player->hXnext += player->hxstep;
		player->hYnext += player->hystep;
	}
}

double	xyhorizonral(t_player *player)
{
	player->hYintercept = floor(player->y / CUBE) * CUBE;
	if (isdown(player))
		player->hYintercept += CUBE;
	player->hXintercept = player->x + ((player->hYintercept - player->y) / tan(player->ray_angle));
	player->hystep = CUBE;
	if (isup(player))
		player->hystep *= -1;
	player->hxstep = CUBE / tan(player->ray_angle);
	if (isleft(player) && player->hxstep > 0)
		player->hxstep *= -1;
	if (isright(player) && player->hxstep < 0)
		player->hxstep *= -1;
	player->hXnext = player->hXintercept;
	player->hYnext = player->hYintercept;
	player->pivot = 0;
	find_wall(player);
	if (player->foundHWall)
		return (distance(player, 0));
	return (INT_MAX);
}
