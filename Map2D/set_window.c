/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:09:56 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/20 16:39:26 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_up_window(t_mlx *mlx, t_player *player)
{
	mlx->mlx = mlx_init(WIDTH * CUBE, HEIGHT * CUBE, "Cub3D", false);
	mlx->img = mlx_new_image(mlx->mlx, WIDTH * CUBE, HEIGHT * CUBE);
	set_up_player(player, mlx);
}
void	keep_window_opened(t_mlx *mlx, t_player *player)
{
	void *param;

	param = player;
	mlx_key_hook(mlx->mlx, ft_hook, param);
	mlx_loop_hook(mlx->mlx, move_player, param);
	mlx_image_to_window(mlx->mlx, mlx->img, 0, 0);
	mlx_loop(mlx->mlx);
	mlx_terminate(mlx->mlx);
}
