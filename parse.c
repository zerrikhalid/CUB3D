/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:21:14 by araji-af          #+#    #+#             */
/*   Updated: 2023/12/20 17:01:31 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	glob_pars(char **av, t_textures *text)
{
	char	**lines;

	lines = split_map(av[1]);
	get_textures(text, lines);
	map_retriever(text, lines);
	check_map(text);
	get_rotaion_angle(text);
}

void	get_rotaion_angle(t_textures *text)
{
	int	i;
	int	j;

	i = 0;
	while (text->mapp[i])
	{
		j = 0;
		while (text->mapp[i][j])
		{
			if (ft_strchr("NEWS", text->mapp[i][j]))
			{
				if (text->mapp[i][j] == 'N')
					text->ra = 270;
				else if (text->mapp[i][j] == 'S')
					text->ra = 90;
				else if (text->mapp[i][j] == 'W')
					text->ra = 180;
				else if (text->mapp[i][j] == 'E')
					text->ra = 0;
				return ;
			}
			j++;
		}
		i++;
	}
}
