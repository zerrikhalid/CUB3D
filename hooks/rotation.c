/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:27:35 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/23 06:05:16 by araji-af         ###   ########.fr       */
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
