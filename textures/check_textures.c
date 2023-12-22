/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 23:17:35 by araji-af          #+#    #+#             */
/*   Updated: 2023/12/22 03:01:59 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_textloads(t_paths *text, t_textures *texture)
{
	if (!text->no || !text->so || !text->ea || !text->we)
	{
		free_map_text(texture);
		free(text);
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
