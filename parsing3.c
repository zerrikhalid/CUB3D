/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:52:09 by araji-af          #+#    #+#             */
/*   Updated: 2023/12/11 17:37:24 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_textures(t_textures *text, char **map)
{
	int		i;
	char	**text_components;

	i = 0;
	initialise_textures(text);
	if (!map)
		map_error(text);
	if (!map[6])
		map_error(text);
	while (map[i] && i < 6)
	{
		if (!ft_strncmp(map[i], "C", 1) || !ft_strncmp(map[i], "F", 1))
			f_s_assignement(map[i], text);
		else
		{
			text_components = ft_split(map[i], ' ');
			check_fill_textures(text_components, text);
		}
		i++;
	}
	if (is_valid_textures(text))
	{
		free_map_text(text);
		exit(1);
	}
}

int	check_borders(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i][j])
	{
		if (map[i][j] != '1' && map[i][j] != ' ' && map[i][j] != '\t')
			return (ft_putstr("Border not closed1\n"), 1);
		j++;
	}
	while (map[i])
		i++;
	i -= 1;
	j = 0;
	while (map[i][j])
	{
		if (map[i][j] != '1' && map[i][j] != ' ' && map[i][j] != '\t')
			return (ft_putstr("Border not closed2\n"), 1);
		j++;
	}
	check_side(map);
	return (0);
}

int	check_side_borders(char	*map)
{
	int	i;

	i = 0;
	if (map[i] != '1' && map[i] != ' ' && map[i] != '\t')
		return (ft_putstr("border not closed3\n"), 1);
	while (map[i])
		i++;
	i -= 1;
	if (map[i] != '1' && map[i] != ' ' && map[i] != '\t')
		return (ft_putstr("border not closed4\n"), 1);
	return (0);
}

int	max_lenght(char **mapp)
{
	int	i;
	int	j;
	int	max;

	i = 6;
	max = 0;
	while (mapp[i])
	{
		j = 0;
		while (mapp[i][j])
			j++;
		if (max < j)
			max = j;
		i++;
	}
	return (max);
}

void	check_map(t_textures *text)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (check_borders(text->mapp) || check_map_caracters(text->mapp))
	{
		free_map_text(text);
		exit(1);
	}
	if (check_pos(text->mapp, text) || check_zero_neighbours(text->mapp))
	{
		free_map_text(text);
		exit(1);
	}
}
