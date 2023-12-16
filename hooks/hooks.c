/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:56:59 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/16 21:39:43 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_hook(void *param)
{
	t_player *player = param;

	if (mlx_is_key_down(player->mlx->mlx, MLX_KEY_UP))
		move_up(player);
	if (mlx_is_key_down(player->mlx->mlx, MLX_KEY_DOWN))
		move_down(player);
	if (mlx_is_key_down(player->mlx->mlx, MLX_KEY_A))
		key_a(player);
	if (mlx_is_key_down(player->mlx->mlx, MLX_KEY_D))
		key_d(player);
	if (mlx_is_key_down(player->mlx->mlx, MLX_KEY_RIGHT))
		move_right(player);
	if (mlx_is_key_down(player->mlx->mlx, MLX_KEY_LEFT))
		move_left(player);
}
