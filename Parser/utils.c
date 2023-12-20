/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:13:51 by araji-af          #+#    #+#             */
/*   Updated: 2023/12/16 23:17:38 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	ft_strcmp(char *av, char *av2)
{
	int	i;

	if (!av)
		return (1);
	i = 0;
	while (av[i] && av2[i] && av[i] == av2[i])
		i++;
	return (av[i] - av2[i]);
}

char	*ft_strchr(char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s != (char)c)
	{
		if (!*s)
		{
			return (NULL);
		}
		s++;
	}
	return ((char *)s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	if (s1 == NULL)
		return (ft_strdup(s2));
	(new = malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2) + 1)));
	if (!new)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	if (!s2)
		return (new[i] = '\0', new);
	while (s2[j])
	{
		new[i] = s2[j];
		j++;
		i++;
	}
	return (new[i] = '\0', new);
}

char	*ft_strdup(char *s1)
{
	char	*str;
	size_t	i;

	if (s1 == NULL)
		return (NULL);
	str = malloc(sizeof (char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
