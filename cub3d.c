/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:11:30 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/25 06:32:40 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void l()
// {
// 	system("leaks cub3D");
// }

int	main(int ac, char **av)
{
	t_mlx		mlx;
	t_player	player;
	t_textures	*texture;
	t_paths		*text_paths;

	if (ac != 2)
		return (ft_putstr("Error\nmap required\n"), 1);
	if (parse_arg(av[1]))
		return (1);
	texture = malloc(sizeof(t_textures));
	memset(texture, 0, sizeof(t_textures));
	text_paths = malloc(sizeof(t_paths));
	memset(text_paths, 0, sizeof(t_paths));
	player.text = texture;
	player.paths = text_paths;
	texture->path = text_paths;
	glob_pars(av, texture);
	load_png(texture);
	set_up_window(&mlx, &player);
	keep_window_opened(&mlx, &player);
	free_map_text(texture);
}
