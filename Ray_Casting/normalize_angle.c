/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_angle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:23:10 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/19 17:23:50 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	ft_normalize(t_player *player)
{
	player->ray_angle = fmod(player->ray_angle, 2 * PI);
	if (player->ray_angle < 0)
		player->ray_angle += (2 * PI);
	return (player->ray_angle);
}
