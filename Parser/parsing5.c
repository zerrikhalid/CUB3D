/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:20:48 by araji-af          #+#    #+#             */
/*   Updated: 2023/12/16 23:18:21 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	f_s_assignement(char *map, t_textures *text)
{
	int		i;
	char	c;

	i = 0;
	c = map[i++];
	while (map[i] == ' ' || map[i] == '\t')
		i++;
	if (c == 'C' && !text->c)
		text->c = ft_strdup(&map[i]);
	else if (c == 'F' && !text->f)
		text->f = ft_strdup(&map[i]);
}

void	check_fill_textures(char **text_components, t_textures *text, char *map)
{
	if (check_texture_args(text_components))
	{
		free_all(text_components);
		free_map_text(text);
		exit(1);
	}
	if (!ft_strcmp(text_components[0], "F")
		|| !ft_strcmp(text_components[0], "C"))
		f_s_assignement(map, text);
	else
		fill_textures(text, text_components);
	free_all(text_components);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((n - 1) && *p1 && *p2 && (*p1 == *p2))
	{
		p1++;
		p2++;
		n--;
	}
	return (*p1 - *p2);
}

int	check_side(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (check_side_borders(map[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}
