/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:08:10 by araji-af          #+#    #+#             */
/*   Updated: 2023/12/16 22:27:44 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_leask(void)
{
	system("leaks cub3D");
}

int	main(int ac, char **av)
{
	char **lines;
	t_textures *text;
	int i = 0;

	// atexit(ft_leask);
	text = NULL;
	if (ac != 2)
		return (ft_putstr("MAP Error\n"), 1);
	if (parse_arg(av[1]))
		return (1);
	text = malloc(sizeof(t_textures));
	lines = split_map(av[1]);
	get_textures(text, lines);
	map_retriever(text, lines);
	check_map(text);
	free_map_text(text);
}
