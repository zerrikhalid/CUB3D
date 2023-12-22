/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:21:59 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/21 17:20:37 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	collision(t_player *player, double next_x, double next_y)
{
	if (player->x < 0 || player->x > player->text->mapp_w || player->y <= 0 || player->y > player->text->mapp_h)
		return (1);
	if (player->text->mapp[(int)((player->y + next_y) / CUBE)][(int)((player->x + next_x) / CUBE)] != '1')
		return (0);
	return (1);
}
