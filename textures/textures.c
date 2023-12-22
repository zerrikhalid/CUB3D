/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:00:16 by araji-af          #+#    #+#             */
/*   Updated: 2023/12/22 03:12:12 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double  get_xtext(double wall_hit, mlx_texture_t *t)
{
	double  xtext;
	double	text_offset;

	text_offset = fmod(wall_hit, CUBE);
	// puts("****");
	// exit(1);
	xtext = (text_offset * t->width) / CUBE;
	return (xtext);
}

double  get_ytext(double yloop, double wsh, mlx_texture_t *t)
{
	double  ytext;
	double  ywall;

	ywall = yloop - ((HEIGHT / 2) - (wsh / 2));
	ytext = (ywall * t->height) / wsh;
	return (ytext);
}

int load_png(t_paths *text, t_textures *texture)
{
	text->no  = mlx_load_png(texture->no);
	text->so = mlx_load_png(texture->so);
	text->ea = mlx_load_png(texture->ea);
	text->we = mlx_load_png(texture->we);
	check_textloads(text, texture);
	return (0);
}

unsigned int	get_texture_color(mlx_texture_t *t, unsigned int x, unsigned int y)
{
	unsigned int	*color;

	color = (unsigned int *)t->pixels + (((t->width) * y) + x);
	return (*color);
}

void	adjust_c(mlx_image_t *image, unsigned int x, unsigned int y, unsigned int c)
{
	unsigned int	*color;

	color = (unsigned int *)image->pixels + (((image->width) * y) + x);
	*color = c;
}
