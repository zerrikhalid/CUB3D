/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:17:47 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/12 10:34:57 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rect(t_mlx *mlx, int x, int y, int color)
{
	int	j;

	mlx->coord1 = x;
	mlx->coord2 = y;
	while (x < (mlx->coord1  + (CUBE)))
	{
		j = y;
		while (j < (mlx->coord2 + (CUBE)))
		{
	 		mlx_put_pixel(mlx->img, j, x, color);
			if (j == (mlx->coord2 + (CUBE - 1))  || x == (mlx->coord1  + (CUBE - 1)) || !x || !j)
	 			mlx_put_pixel(mlx->img, j, x, color ^ 0xffffff00);
			j++;
		}
		x++;
	}
}
