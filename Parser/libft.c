/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:28:45 by araji-af          #+#    #+#             */
/*   Updated: 2023/12/25 06:02:50 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_bspace(void *b, size_t n)
{
	unsigned char	*dest;
	size_t			i;

	dest = b;
	i = 0;
	while (i++ < n)
		*dest++ = ' ';
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(size * count);
	if (!ptr)
		return (NULL);
	ft_bspace(ptr, count * size);
	return (ptr);
}

int	ft_strcpy(char *dst, char *src)
{
	int	count;

	count = 0;
	while (src[count] != '\0')
	{
		dst[count] = src[count];
		count++;
	}
	return (ft_strlen(src));
}

int	is_valid_textures(t_textures *text)
{
	char			**str;
	unsigned int	c;

	c = 0;
	if (!text->no || !text->so || !text->we
		|| !text->ea || !text->c || !text->f)
		return (ft_putstr("Error\nError in texture\n"), 1);
	if (check_c_f(text->c) || check_c_f(text->f))
		return (1);
	str = ft_split_set(text->c, " \t,");
	c = ft_atoi(str[0]) << 24 | ft_atoi(str[1]) << 16 | ft_atoi(str[2]) << 8
		| 255;
	text->c_color = c;
	free_all(str);
	str = ft_split_set(text->f, " \t,");
	c = ft_atoi(str[0]) << 24 | ft_atoi(str[1]) << 16 | ft_atoi(str[2]) << 8
		| 255;
	text->f_color = c;
	free_all(str);
	return (0);
}

int	ft_atoi(char *s)
{
	int			sign;
	long long	nb;
	int			n;

	nb = 0;
	sign = 1;
	if (*s == '+')
		s++;
	if (*s == '-' && s++)
		return (-1);
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (-1);
		n = (*s - 48) * sign;
		if (nb > (LLONG_MAX / 10) || (nb == (LLONG_MAX / 10) && n > 7))
			return (-1);
		if (nb < (LLONG_MIN / 10) || (nb == (LLONG_MIN / 10) && n < -8))
			return (-1);
		nb = nb * 10 + n;
		s++;
	}
	return (nb);
}
