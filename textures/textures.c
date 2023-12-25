/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:00:16 by araji-af          #+#    #+#             */
/*   Updated: 2023/12/25 06:25:45 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	get_xtext(double wall_hit, mlx_texture_t *t)
{
	double	xtext;
	double	text_offset;

	text_offset = fmod(wall_hit, CUBE);
	xtext = (text_offset * t->width) / CUBE;
	return (xtext);
}

double	get_ytext(double yloop, double wsh, mlx_texture_t *t)
{
	double	ytext;
	double	ywall;

	ywall = yloop - ((HEIGHT / 2) - (wsh / 2));
	ytext = (ywall * t->height) / wsh;
	return (ytext);
}

void	load_png(t_textures *texture)
{
	texture->path->no = mlx_load_png(texture->no);
	texture->path->so = mlx_load_png(texture->so);
	texture->path->we = mlx_load_png(texture->we);
	texture->path->ea = mlx_load_png(texture->ea);
	texture->path->frame1 = mlx_load_png("frames/frame1.png");
	texture->path->frame2 = mlx_load_png("frames/frame2.png");
	check_textloads(texture);
}

unsigned int	get_texture_color(mlx_texture_t *t,
					unsigned int x, unsigned int y)
{
	unsigned int	*color;

	color = (unsigned int *)t->pixels + (((t->width) * y) + x);
	return (*color);
}

void	adjust_c(mlx_image_t *image, unsigned int x,
			unsigned int y, unsigned int c)
{
	unsigned int	*color;

	color = (unsigned int *)image->pixels + (((image->width) * y) + x);
	*color = c;
}
