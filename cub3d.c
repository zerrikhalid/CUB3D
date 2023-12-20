/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:11:30 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/21 00:34:40 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void l()
// {
	// system("leaks cub3D");
// }

int main(int ac, char **av)
{
	t_mlx		mlx;
	t_player	player;
	t_textures	*text;

	// atexit(l);
	if (ac != 2)
		return (ft_putstr("Error\n"), 1);
	if (parse_arg(av[1]))
		return (1);
	text = NULL;
	text = malloc(sizeof(t_textures));

	glob_pars(av, text);
	player.text = text;
	set_up_window(&mlx, &player);
	keep_window_opened(&mlx, &player);
	free_map_text(text);
}
