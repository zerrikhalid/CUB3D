/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:35:16 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/16 21:50:47 by kzerri           ###   ########.fr       */
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

double distance(t_player *player, int c)
{
	if (!c)
		return (sqrt(pow(player->hXhitwall - player->x, 2) + pow(player->hYhitwall - player->y, 2)));
	return (sqrt(pow(player->vXhitwall - player->x, 2) + pow(player->vYhitwall - player->y, 2)));
}

double	ft_normalize(t_player *player)
{
    player->ray_angle = fmod(player->ray_angle, 2 * PI);
	if (player->ray_angle < 0)
		player->ray_angle += (2 * PI);
	return (player->ray_angle);
}

double	xyhorizonral(t_player *player)
{
	player->ray_angle = ft_normalize(player);
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
	if (isup(player))
		player->hYnext--;
	while (player->hXnext >= 0 && player->hXnext <= (WIDTH * CUBE) &&
		player->hYnext >= 0 && player->hYnext <= (HEIGHT * CUBE))
	{
		if (matrix3[(int)player->hYnext / 64][(int)player->hXnext / 64] == 1)
		{
			player->foundHWall = true;
			player->hXhitwall = player->hXnext;
			player->hYhitwall = player->hYnext;
			break ;
		}
		player->hXnext += player->hxstep;
		player->hYnext += player->hystep;
	}
	if (player->foundHWall)
		return (distance(player, 0));
	else
		return (INT_MAX);
}

double xyVertical(t_player *player)
{
	player->ray_angle = ft_normalize(player);
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
	if (isleft(player))
		player->vXnext--;
	while (player->vXnext >= 0 && player->vXnext <= (WIDTH * CUBE) &&
		player->vYnext >= 0 && player->vYnext <= (HEIGHT * CUBE))
	{
		if (matrix3[(int)player->vYnext / 64][(int)player->vXnext / 64] == 1)
		{
			player->foundVWall = true;
			player->vXhitwall = player->vXnext;
			player->vYhitwall = player->vYnext;
			break ;
		}
		player->vXnext += player->vxstep;
		player->vYnext += player->vystep;
	}
	if (player->foundVWall)
		return (distance(player, 1));
	else
		return (INT_MAX);
}

void	raycasting(t_player *player)
{
	player->ray_angle = d_to_r(player->rotationAngle) - (FOV / 2);
	double	fv;
	int i;

	fv = NUM_RAYS;
	i = 0;
	while (i < WIDTH * 64)
	{
		player->foundHWall = false;
		player->foundVWall = false;
		if (xyhorizonral(player) < xyVertical(player))
			line(player->mlx, player->x, player->y, player->hXhitwall, player->hYhitwall);
		else
			line(player->mlx, player->x, player->y, player->vXhitwall, player->vYhitwall);
		player->ray_angle += FOV / 960;
		i++;
	}
}
