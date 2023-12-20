/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:12:03 by araji-af          #+#    #+#             */
/*   Updated: 2023/12/16 22:28:19 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strlen(char *s)
{
	int	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_substr(char *s, int start, int len)
{
	unsigned int	i;
	char const		*subs;	
	char			*a;

	if (!s)
		return (NULL);
	if (!len || start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		subs = malloc((sizeof (char) * (ft_strlen(s) - start + 1)));
	else
		subs = malloc((sizeof (char) * (len + 2)));
	if (!subs)
		return (NULL);
	i = 0;
	a = (char *)subs;
	while (len-- && s[start])
		a[i++] = s[start++];
	a[i] = '\0';
	return ((char *)subs);
}

static char	*join_free(int fd, char *holder)
{
	char	*tmp;
	int		bytes;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes = 1;
	buffer[0] = 0;
	while (bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == 0)
			return (free(buffer), holder);
		if (bytes < 0)
			return (free(buffer), NULL);
		buffer[bytes] = 0;
		tmp = holder;
		holder = ft_strjoin(tmp, buffer);
		free(tmp);
	}
	return (free(buffer), holder);
}

static int	strlen_new_line(char *buffer)
{
	int	i;

	if (!buffer)
		return (0);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*updatable;
	char		*free_this_one;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	updatable = join_free(fd, updatable);
	if (!updatable)
		return (NULL);
	if (!*updatable)
	{
		free(updatable);
		updatable = NULL;
		return (NULL);
	}
	free_this_one = updatable;
	line = ft_substr(free_this_one, 0, strlen_new_line(free_this_one) + 1);
	updatable = ft_substr(free_this_one, strlen_new_line(line) + 1,
			ft_strlen(free_this_one + strlen_new_line(free_this_one)));
	free(free_this_one);
	return (line);
}
