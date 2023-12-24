/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:17:47 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/24 22:06:44 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rect(t_mlx *mlx, int x, int y, int color)
{
	int	j;

	mlx->coord1 = x;
	mlx->coord2 = y;
	while (x < (mlx->coord1 + (CUBE - 1)))
	{
		j = y;
		while (j < (mlx->coord2 + (CUBE - 1)))
		{
			mlx_put_pixel(mlx->img, j, x, color);
			j++;
		}
		x++;
	}
}
