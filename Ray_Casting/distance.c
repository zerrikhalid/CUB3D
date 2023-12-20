/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:24:56 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/19 17:25:26 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	distance(t_player *player, int c)
{
	if (!c)
		return (sqrt(pow(player->hXhitwall - player->x, 2) + pow(player->hYhitwall - player->y, 2)));
	return (sqrt(pow(player->vXhitwall - player->x, 2) + pow(player->vYhitwall - player->y, 2)));
}
