/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:24:56 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/24 23:13:35 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	distance(t_player *player, int c)
{
	if (!c)
		return (sqrt(pow(player->hxhitwall - player->x, 2)
				+ pow(player->hyhitwall - player->y, 2)));
	return (sqrt(pow(player->vxhitwall - player->x, 2)
			+ pow(player->vyhitwall - player->y, 2)));
}
