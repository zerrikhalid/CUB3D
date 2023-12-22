/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:29:50 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/22 17:29:53 by kzerri           ###   ########.fr       */
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
