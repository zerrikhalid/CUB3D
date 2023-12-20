/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 02:50:48 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/18 22:39:07 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	esc(t_player *player)
{
	mlx_delete_image(player->mlx->mlx, player->mlx->img);
	mlx_close_window(player->mlx->mlx);
	player->mlx->mlx = NULL;
	exit(0);
}
