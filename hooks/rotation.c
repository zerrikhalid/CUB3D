/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:27:35 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/24 22:55:44 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotate(t_player *player)
{
	player->rotationangle += player->rotationspeed * player->turndirection;
	if (player->rotationangle > 360)
		player->rotationangle -= 360;
	if (player->rotationangle < 0)
		player->rotationangle += 360;
}
