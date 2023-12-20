/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:11:09 by araji-af          #+#    #+#             */
/*   Updated: 2023/12/16 22:28:39 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	del_set(char **str, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(str[j]);
		j++;
	}
	free(str);
	*str = NULL;
}

static int	word_len_set(char *s, char *set)
{
	int	len;

	len = 0;
	while (!ft_strchr(set, *s) && *s)
	{
		s++;
		len++;
	}
	return (len);
}

static int	countword_set(char *s, char *set)
{
	int			i;
	int			isword;

	i = 0;
	isword = 0;
	while (ft_strchr(set, *s))
		s++;
	while (*s)
	{
		if (!ft_strchr(set, *s) && isword == 0)
		{
			isword = 1;
			i++;
		}
		else if (ft_strchr(set, *s) && !ft_strchr(set, *(s + 1)))
			isword = 0;
		s++;
	}
	return (i);
}

static void	putword_set(char **splited, char *s, char *set)
{
	int	i;
	int	word;

	i = 0;
	while (*s)
	{
		while (ft_strchr(set, *s) && *s)
			s++;
		if (!*s)
			break ;
		word = word_len_set(s, set);
		splited[i] = ft_substr(s, 0, word);
		if (splited[i] == NULL)
		{
			del_set(splited, i);
			return ;
		}
		s += word;
		i++;
	}
	splited[i] = NULL;
}

char	**ft_split_set(char *s, char *set)
{
	char	**splited;

	if (s == NULL)
		return (NULL);
	splited = (char **)malloc(sizeof(char *) * (countword_set(s, set) + 1));
	if (!splited)
		return (NULL);
	putword_set(splited, s, set);
	return (splited);
}
