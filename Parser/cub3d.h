/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:04:53 by araji-af          #+#    #+#             */
/*   Updated: 2023/12/16 16:35:26 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <limits.h>

# define BUFFER_SIZE 10
# define WI 600
# define HI 400
# define TL 32

typedef struct s_textures
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	char	**mapp;
	int		x;
	int		y;
	int		c_color;
	int		f_color;
}	t_textures;

void	ft_putstr(char *s);
int		ft_strcmp(char *av, char *av2);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
char	*ft_substr(char	*s, int start, int len);
int		ft_strlen(char *s);
char	*get_next_line(int fd);
char	**ft_split(char *s, char c);
char	**split_map(char *av);
int		parse_arg(char *av);
int		ft_strncmp(char *s1, char *s2, int n);
void	get_textures(t_textures *text, char **map_components);
void	fill_textures(t_textures *text, char **text_components);
void	free_all(char **av);
void	initialise_textures(t_textures *text);
void	check_map(t_textures *text);
int		check_side_borders(char	*map_line);
int		check_borders(char **map);
int		check_player(char **map_components);
int		check_pos(char **map, t_textures *text);
int		check_zero_neighbours(char **map);
void	ft_bspace(void *b, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_strcpy(char *dst, char *src);
char	**map_retriever(t_textures	*text, char	**map);
int		max_lenght(char	**map);
int		check_texture_args(char **av);
int		is_valid_textures(t_textures *text);
void	free_map_text(t_textures *text);
int		check_pos_helper(char **map, int *player, t_textures *text);
int		check_map_caracters(char **map);
int		ft_atoi(char *s);
char	**ft_split_set(char *s, char *set);
int		check_c_f(char *s);
int		check_colors_range(char **s);
void	map_error(t_textures *text);
void	f_s_assignement(char *map, t_textures *text);
void	check_fill_textures(char **texte, t_textures *text, char *map);
int		check_side(char **map);
int		ft_isdigit(int c);

#endif