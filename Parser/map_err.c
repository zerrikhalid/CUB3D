/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 02:50:56 by araji-af          #+#    #+#             */
/*   Updated: 2023/12/24 22:50:16 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	count;

	count = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[count] != '\0' && count < (dstsize - 1))
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (ft_strlen(src));
}

static char	*ft_strtrim(char *s1, char *set)
{
	size_t			start;
	size_t			end;
	char			*new;

	start = 0;
	if (s1 == NULL)
		return (NULL);
	end = ft_strlen(s1);
	if (set == NULL)
		return ((char *)s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (ft_strchr(set, (s1[end - 1])) && end - start > 0)
		end--;
	new = (char *)malloc(sizeof (char) * (end - start + 1));
	if (!new)
		return (NULL);
	ft_strlcpy(new, &s1[start], end - start + 1);
	return (new);
}

int	get_real_height(char *map)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map[i] && count < 6)
	{
		if (map[i] == '\n' && map[i + 1] != '\n')
			count++;
		i++;
	}
	return (i);
}

int	is_map_valid(char *line)
{
	int		i;
	char	*trimed;
	int		flag;

	i = get_real_height(line);
	trimed = ft_strtrim(line, "\n");
	flag = 0;
	while (trimed[i])
	{
		if (trimed[i] == '\n' && trimed[i + 1] == '\n')
			return (free(trimed), 1);
		i++;
	}
	return (free(trimed), 0);
}
