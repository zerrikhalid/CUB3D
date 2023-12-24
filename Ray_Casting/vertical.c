/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:28:58 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/24 23:15:25 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	find_wall(t_player *player)
{
	int	a;
	int	b;

	while (player->vxnext >= 0 && player->vxnext < player->text->mapp_w
		&& player->vynext >= 0 && player->vynext < player->text->mapp_h)
	{
		if (isleft(player))
			player->pivot = 1;
		a = (int)player->vynext / CUBE;
		b = (int)(player->vxnext - player->pivot) / CUBE;
		if (player->text->mapp[a][b] == '1')
		{
			player->foundvwall = true;
			player->vxhitwall = player->vxnext;
			player->vyhitwall = player->vynext;
			break ;
		}
		player->vxnext += player->vxstep;
		player->vynext += player->vystep;
	}
}

double	xyvertical(t_player *player)
{
	player->vxintercept = floor(player->x / CUBE) * CUBE;
	if (isright(player))
		player->vxintercept += CUBE;
	player->vyintercept = player->y + ((player->vxintercept - player->x)
			* tan(player->ray_angle));
	player->vxstep = CUBE;
	if (isleft(player))
		player->vxstep *= -1;
	player->vystep = CUBE * tan(player->ray_angle);
	if (isup(player) && player->vystep > 0)
		player->vystep *= -1;
	if (isdown(player) && player->vystep < 0)
		player->vystep *= -1;
	player->vxnext = player->vxintercept;
	player->vynext = player->vyintercept;
	player->pivot = 0;
	find_wall(player);
	if (player->foundvwall)
		return (distance(player, 1));
	return (INT_MAX);
}
