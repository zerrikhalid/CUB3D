/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:28:45 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/24 23:14:28 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	find_wall(t_player *player)
{
	int	a;
	int	b;

	while (player->hxnext >= 0 && player->hxnext < player->text->mapp_w
		&& player->hynext >= 0 && player->hynext < player->text->mapp_h)
	{
		if (isup(player))
			player->pivot = 1;
		a = (int)(player->hynext - player->pivot) / CUBE;
		b = (int)player->hxnext / CUBE;
		if (player->text->mapp[a][b] == '1')
		{
			player->foundhwall = true;
			player->hxhitwall = player->hxnext;
			player->hyhitwall = player->hynext;
			break ;
		}
		player->hxnext += player->hxstep;
		player->hynext += player->hystep;
	}
}

double	xyhorizonral(t_player *player)
{
	player->hyintercept = floor(player->y / CUBE) * CUBE;
	if (isdown(player))
		player->hyintercept += CUBE;
	player->hxintercept = player->x + ((player->hyintercept - player->y)
			/ tan(player->ray_angle));
	player->hystep = CUBE;
	if (isup(player))
		player->hystep *= -1;
	player->hxstep = CUBE / tan(player->ray_angle);
	if (isleft(player) && player->hxstep > 0)
		player->hxstep *= -1;
	if (isright(player) && player->hxstep < 0)
		player->hxstep *= -1;
	player->hxnext = player->hxintercept;
	player->hynext = player->hyintercept;
	player->pivot = 0;
	find_wall(player);
	if (player->foundhwall)
		return (distance(player, 0));
	return (INT_MAX);
}
