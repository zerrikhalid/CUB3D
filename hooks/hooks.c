/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:56:59 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/24 23:04:35 by kzerri           ###   ########.fr       */
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
		player->sidedirection = 0;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		player->sidedirection = 0;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		player->turndirection = 0;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		player->turndirection = 0;
}

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_player	*player;

	player = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		player->walkdirection = 1;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		player->walkdirection = -1;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		player->sidedirection = -1;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		player->sidedirection = 1;
	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
		player->stop_mouse *= -1;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		player->turndirection = 1;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		player->turndirection = -1;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		esc(player);
	ft_release(keydata, player);
}

void	ft_mouse_hook(mouse_key_t keydata, action_t action,
			modifier_key_t mods, void *param)
{
	t_player	*player;

	player = param;
	(void)mods;
	if (keydata == 0 && action == 1)
		put_fframe(player, 1);
	if (keydata == 0 && action == 0)
		put_fframe(player, 0);
}
