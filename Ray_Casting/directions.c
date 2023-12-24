/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:51:16 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/24 22:13:33 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	isup(t_player *player)
{
	if (player->ray_angle > PI && player->ray_angle < (2 * PI))
		return (1);
	return (0);
}

int	isdown(t_player *player)
{
	if (player->ray_angle < PI && player->ray_angle > 0)
		return (1);
	return (0);
}

int	isleft(t_player *player)
{
	if (player->ray_angle > (PI / 2) && player->ray_angle < (3 * (PI / 2)))
		return (1);
	return (0);
}

int	isright(t_player *player)
{
	if (player->ray_angle < (PI / 2) || player->ray_angle > (3 * (PI / 2)))
		return (1);
	return (0);
}
