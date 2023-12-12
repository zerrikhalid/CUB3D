/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:56:59 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/11 18:29:44 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_hook(void *param)
{
	t_player *player = param;

	if (mlx_is_key_down(player->mlx->mlx, MLX_KEY_UP))
		move_up(player);
	else if (mlx_is_key_down(player->mlx->mlx, MLX_KEY_DOWN))
		move_down(player);
	else if (mlx_is_key_down(player->mlx->mlx, MLX_KEY_A))
		key_a(player);
	else if (mlx_is_key_down(player->mlx->mlx, MLX_KEY_D))
		key_d(player);
	else if (mlx_is_key_down(player->mlx->mlx, MLX_KEY_RIGHT))
		move_right(player);
	else if (mlx_is_key_down(player->mlx->mlx, MLX_KEY_LEFT))
		move_left(player);
}
