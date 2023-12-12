/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_right.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:27:35 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/12 11:04:28 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_right(t_player *player)
{
	player->rotationAngle += player->rotationSpeed;
	create_2d_map(player->mlx, NULL);
	move_player(player, player->mlx);
}
