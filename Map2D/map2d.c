/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:09:41 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/21 23:08:54 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	create_2d_map(t_mlx *mlx, char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == '1')
				rect(mlx, x * CUBE, y * CUBE, 0x000000FF);
			else
				rect(mlx, x * CUBE, y * CUBE, 0xFFFFFFFF);
			y++;
		}
		x++;
	}
}
