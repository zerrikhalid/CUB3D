/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 21:19:56 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/24 22:06:14 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	circle(t_player *player, t_mlx *mlx)
{
	int	h;
	int	k;
	int	x;
	int	y;

	h = player->x - CUBE;
	k = player->y - CUBE;
	x = h;
	while (x <= player->x + CUBE)
	{
		y = k;
		while (y <= player->y + CUBE)
		{
			if (pow(x - player->x, 2)
				+ pow(y - player->y, 2) <= pow(player->radius, 2))
				mlx_put_pixel(mlx->img, x, y, 0xFF0000FF);
			y++;
		}
		x++;
	}
}
