/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:41:06 by araji-af          #+#    #+#             */
/*   Updated: 2023/12/12 14:12:42 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_map_caracters(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1'
				&& map[i][j] != 'N' && map[i][j] != 'S'
				&& map[i][j] != 'E' && map[i][j] != 'W'
				&& map[i][j] != ' ' && map[i][j] != '\t')
			{
				ft_putstr("Invalid caracters in map\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	fill_textures(t_textures *text, char **text_components)
{
	if (!ft_strcmp(text_components[0], "NO") && !text->no)
		text->no = ft_strdup(text_components[1]);
	else if (!ft_strcmp(text_components[0], "SO") && !text->so)
		text->so = ft_strdup(text_components[1]);
	else if (!ft_strcmp(text_components[0], "WE") && !text->we)
		text->we = ft_strdup(text_components[1]);
	else if (!ft_strcmp(text_components[0], "EA") && !text->ea)
		text->ea = ft_strdup(text_components[1]);
}

int	check_c_f(char *s)
{
	int		i;
	int		count;
	char	**str;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		return (ft_putstr("Error in Textures1\n"), 1);
	str = ft_split_set(s);
	i = 0;
	while (str && str[i])
		i++;
	if (i != 3)
		return (free_all(str), ft_putstr("Error in Textures2\n"), 1);
	if (check_colors_range(str))
		return (free_all(str), ft_putstr("Error in color range\n"), 1);
	free_all(str);
	return (0);
}

int	check_colors_range(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_atoi(s[i]) >= 0 && ft_atoi(s[i]) <= 255 && ft_atoi(s[i]) != -1)
			i++;
		else
			return (1);
	}
	return (0);
}

void	map_error(t_textures *text)
{
	ft_putstr("Error in map\n");
	free(text);
	exit(1);
}
