/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:27:35 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/18 19:32:31 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotate(t_player *player)
{
	player->rotationAngle += player->rotationSpeed * player->turndirection;
	if (player->rotationAngle > 360)
		player->rotationAngle -= 360;
	if (player->rotationAngle < 0)
		player->rotationAngle += 360;
} 
 