/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 22:10:42 by araji-af          #+#    #+#             */
/*   Updated: 2023/12/25 06:59:42 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_fframe(t_player *player, int flag)
{
	if (flag == 1)
	{
		mlx_delete_image(player->mlx->mlx, player->mlx->text);
		player->mlx->text = mlx_texture_to_image(player->mlx->mlx,
				player->paths->frame2);
		mlx_image_to_window(player->mlx->mlx, player->mlx->text, 120, 125);
	}
	else
	{
		mlx_delete_image(player->mlx->mlx, player->mlx->text);
		player->mlx->text = mlx_texture_to_image(player->mlx->mlx,
				player->paths->frame1);
		mlx_image_to_window(player->mlx->mlx, player->mlx->text, 100, 125);
	}
}

void	check_frames(t_textures *text)
{
	if (text->path->frame1)
		mlx_delete_texture(text->path->frame1);
	if (text->path->frame2)
		mlx_delete_texture(text->path->frame2);
}
