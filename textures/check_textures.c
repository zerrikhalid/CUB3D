/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 23:17:35 by araji-af          #+#    #+#             */
/*   Updated: 2023/12/22 01:43:23 by araji-af         ###   ########.fr       */
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
void	check_wich_tx(t_paths *text, t_player *player, double *x)
{
	if (player->is_vert)
	{
		if (sin(player->ray_angle) > 0)
			*x = get_xtext(player->wall_inter, text->so);
		else
			*x = get_xtext(player->wall_inter, text->no);
	}
	else
	{
		if (cos(player->ray_angle > 0))
			*x = get_xtext(player->wall_inter, text->ea);	
		else
			*x = get_xtext(player->wall_inter, text->we);
	}
}
void	check_wich_ty(t_paths *text, t_player *player, int topheight , double *y)
{
	if (player->is_vert)
	{
		if (sin(player->ray_angle) > 0)
			*y = get_ytext(topheight, player->wallstripheight, text->so);
		else
			*y = get_ytext(topheight, player->wallstripheight, text->no);
	}
	else
	{
		if (cos(player->ray_angle > 0))
			*y = get_ytext(topheight, player->wallstripheight, text->ea);
		else
			*y = get_ytext(topheight, player->wallstripheight, text->we);
	}
}
