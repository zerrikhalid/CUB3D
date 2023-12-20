/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:56:59 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/20 16:20:44 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_release(mlx_key_data_t keydata, t_player *player)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		player->walkdirection = 0;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		player->walkdirection = 0;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		player->sideDirection = 0;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		player->sideDirection = 0;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		player->turndirection = 0;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		player->turndirection = 0;
}

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_player *player;

	player = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		player->walkdirection = 1;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		player->walkdirection = -1;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		player->sideDirection = -1;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		player->sideDirection = 1;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		player->turndirection = 1;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		player->turndirection = -1;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		esc(player);
	ft_release(keydata, player);
}
