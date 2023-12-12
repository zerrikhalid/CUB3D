/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:08:10 by araji-af          #+#    #+#             */
/*   Updated: 2023/12/12 14:19:27 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// void	ft_leask(void)
// {
// 	system("leaks cub3D");
// }

// int	main(int ac, char **av)
// {
// 	char **lines;
// 	t_textures *text;
// 	int i = 0;

// 	atexit(ft_leask);
// 	text = NULL;
// 	if (ac != 2)
// 		return (ft_putstr("MAP Error\n"), 1);
// 	if (parse_arg(av[1]))
// 		return (1);
// 	text = malloc(sizeof(t_textures));
// 	lines = split_map(av[1]);
// 	get_textures(text, lines);
// 	map_retriever(text, lines);
// 	check_map(text);
// 	printf("SO : %s\n", text->so);
// 	printf("WE : %s\n", text->we);
// 	printf("NO : %s\n", text->no);
// 	printf("EA : %s\n", text->ea);
// 	printf("F : %s\n", text->f);
// 	printf("C : %s\n", text->c);
// 	while (text->mapp[i])
// 		printf("%s\n", text->mapp[i++]);
// 	free_map_text(text);
// }
