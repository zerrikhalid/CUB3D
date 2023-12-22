/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:21:59 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/22 03:23:50 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	collision(t_player *player, double next_x, double next_y)
{
	if (next_x <= 0 || next_x > player->text->mapp_w || next_y <= 0 || next_y > player->text->mapp_h)
		return (1);
	if (player->text->mapp[(int)(next_y / CUBE)][(int)(next_x / CUBE)] != '1')
		return (0);
	return (1);
}
