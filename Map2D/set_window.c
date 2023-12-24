/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:09:56 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/24 22:12:19 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_up_window(t_mlx *mlx, t_player *player)
{
	mlx->mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", false);
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	set_up_player(player, mlx);
}

void	keep_window_opened(t_mlx *mlx, t_player *player)
{
	void	*param;

	param = player;
	mlx_key_hook(mlx->mlx, &ft_hook, param);
	mlx_mouse_hook(mlx->mlx, &ft_mouse_hook, param);
	mlx_loop_hook(mlx->mlx, &move_player, param);
	mlx_image_to_window(mlx->mlx, mlx->img, 0, 0);
	put_fframe(player, 0);
	mlx_loop(mlx->mlx);
	mlx_terminate(mlx->mlx);
}
