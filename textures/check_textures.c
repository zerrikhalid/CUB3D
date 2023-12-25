/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 23:17:35 by araji-af          #+#    #+#             */
/*   Updated: 2023/12/25 06:20:09 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_textloads(t_textures *texture)
{
	if (!texture->path->no || !texture->path->so
		|| !texture->path->ea || !texture->path->we)
	{
		ft_putstr("Error\nFailed to load PNG!!");
		free_map_text(texture);
		check_frames(texture);
		exit(1);
	}
}

mlx_texture_t	*check_wich_tx(t_paths *paths, t_player *player)
{
	if (player->is_vert)
	{
		if (cos(player->ray_angle) > 0)
			return (paths->ea);
		else
			return (paths->we);
	}
	else
	{
		if (sin(player->ray_angle) > 0)
			return (paths->so);
		else
			return (paths->no);
	}
}
