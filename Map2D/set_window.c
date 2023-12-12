/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:09:56 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/10 15:30:43 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_up_window(t_mlx *mlx, t_player *player)
{
	mlx->mlx = mlx_init(WIDTH * CUBE, HEIGHT * CUBE, "Cub3D", false);
	mlx->img = mlx_new_image(mlx->mlx, WIDTH * CUBE, HEIGHT * CUBE);
	create_2d_map(mlx, NULL);
	set_up_player(player, mlx);
}

void	keep_window_opened(t_mlx *mlx, t_player *player)
{
	mlx_loop_hook(mlx->mlx, ft_hook, player);
	mlx_image_to_window(mlx->mlx, mlx->img, 0, 0);
	mlx_loop(mlx->mlx);
	mlx_terminate(mlx->mlx);
}
