/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:07:38 by araji-af          #+#    #+#             */
/*   Updated: 2023/12/24 01:01:21 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_map_text(t_textures *text)
{
	int	i;

	i = 0;
	free(text->no);
	free(text->so);
	free(text->we);
	free(text->ea);
	free(text->f);
	free(text->c);
	if (text->path->no)
		mlx_delete_texture(text->path->no);
	if (text->path->so)
		mlx_delete_texture(text->path->so);
	if (text->path->we)
		mlx_delete_texture(text->path->we);
	if (text->path->ea)
		mlx_delete_texture(text->path->ea);
	free(text->path);
	while (text->mapp && text->mapp[i])
	{
		free(text->mapp[i]);
		i++;
	}
	free(text->mapp);
	free(text);
}

void	map_retriever(t_textures *text, char **map)
{
	int		i;
	int		j;

	i = 6;
	j = 0;
	while (map[i])
	{
		i++;
		j++;
	}
	text->mapp = malloc(sizeof(char *) * (j + 1));
	text->mapp_w = max_lenght(map);
	if (!text->mapp)
		return ;
	i = 0;
	j = 6;
	while (map[j])
	{
		text->mapp[i] = ft_calloc(text->mapp_w + 1, 1);
		ft_strcpy(text->mapp[i], map[j]);
		text->mapp[i][max_lenght(map)] = 0;
		i++;
		j++;
	}
	return (text->mapp[i] = 0, free_all(map), free(NULL));
}

int	check_pos(char **map, t_textures *text)
{
	int	player;

	player = 0;
	if (check_pos_helper(map, &player, text))
	{
		ft_putstr("Player neighbour is invalid\n");
		return (1);
	}
	if (player == 1)
		return (0);
	ft_putstr("More than one player or non found\n");
	return (1);
}

int	check_zero_neighbours(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				if ((!ft_strchr("01NSWE", map[i][j - 1]))
					|| !ft_strchr("01NSWE", map[i][j + 1])
					|| (!ft_strchr("01NSWE", map[i - 1][j]))
					|| !ft_strchr("01NSWE", map[i + 1][j]))
				{
					ft_putstr("Zero neignbour is invalid\n");
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_pos_helper(char **map, int *player, t_textures *text)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				*player += 1;
				if ((map[i][j - 1] != '0' && map[i][j - 1] != '1')
					|| (map[i][j + 1] != '0' && map[i][j + 1] != '1')
					|| (map[i + 1][j] != '0' && map[i + 1][j] != '1')
					|| (map[i - 1][j] != '0' && map[i - 1][j] != '1'))
					return (1);
				text->x = j;
				text->y = i;
			}
			j++;
		}
	}
	return (0);
}
