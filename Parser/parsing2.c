/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:26:32 by araji-af          #+#    #+#             */
/*   Updated: 2023/12/24 22:48:13 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	parse_arg(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] == '.')
		{
			if (!ft_strcmp(&av[i], ".cub"))
				return (0);
		}
		i++;
	}
	return (ft_putstr("Wrong Extention\n"), 1);
}

char	**split_map(t_textures *text, char *av)
{
	int		fd;
	char	**lines;
	char	*line;
	char	*line2;
	char	*tmp;

	lines = NULL;
	fd = open(av, O_CREAT | O_RDWR, 0777);
	line = get_next_line(fd);
	line2 = get_next_line(fd);
	while (line2)
	{
		tmp = line;
		line = ft_strjoin(line, line2);
		free(line2);
		free(tmp);
		line2 = get_next_line(fd);
	}
	text->map_valid = is_map_valid(line);
	lines = ft_split(line, '\n');
	free(line);
	if (text->map_valid)
		new_line_err();
	close(fd);
	return (lines);
}

void	free_all(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
	av = NULL;
}

int	check_texture_args(char **av)
{
	int	i;

	i = 0;
	if (!ft_strcmp(av[i], "C") || !ft_strcmp(av[i], "F"))
		return (0);
	while (av[i])
		i++;
	if (i != 2)
	{
		ft_putstr("Wrong format in texture\n");
		return (1);
	}
	return (0);
}

void	initialise_textures(t_textures *text)
{
	text->no = NULL;
	text->so = NULL;
	text->we = NULL;
	text->ea = NULL;
	text->f = NULL;
	text->c = NULL;
	text->mapp = NULL;
	text->c_color = -1;
	text->f_color = -1;
}
