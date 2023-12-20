/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:31:02 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/19 20:07:22 by kzerri           ###   ########.fr       */
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
# include <stdbool.h>
# include <limits.h>
# include "mlx42.h"

# define PI  M_PI 
# define CUBE 64
# define SCALE 0.2
# define WIDTH 15
# define HEIGHT 11
# define BUFFER_SIZE 10
# define NUM_RAYS (WIDTH * CUBE)
# define FOV (60.0 * (PI / 180.0))

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

typedef struct s_mlx
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	double			coord1;
	double			coord2;
	int				color;
	t_textures		*texture;
}t_mlx;

typedef struct s_player
{
	double	x;
	double	y;
	double	pivot;
	double	hXintercept;
	double 	hYintercept;
	double	hXnext;
	double	hYnext;
	double	vXintercept;
	double 	vYintercept;
	double	vXnext;
	double	vYnext;
	double	vxstep;
	double	vystep;
	double	hxstep;
	double	hystep;
	double	hXhitwall;
	double	hYhitwall;
	double	vXhitwall;
	double	vYhitwall;
	double	ray_angle;
	int		foundHWall;
	int		foundVWall;
	double	radius;
	double	rotationAngle;
	double	moveSpeed;
	double	rotationSpeed;
	double	v_distance;
	double	h_distance;
	double	turndirection;
	double	walkdirection;
	double	sideDirection;
	double	distance_p_plane;
	double	wallstripheight;
	t_mlx	*mlx;
}t_player;

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
void	check_fill_textures(char **text_components, t_textures *text, char *map);
int		check_side(char **map);
double	d_to_r(double deg);
void	set_up_window(t_mlx *mlx, t_player *player);
void	keep_window_opened(t_mlx *mlx, t_player *player);
void	create_2d_map(t_mlx *mlx, char **map);
void	set_up_player(t_player *player, t_mlx *mlx);
void	rect(t_mlx *mlx, int x, int y, int color);
void	circle(t_player *player, t_mlx *mlx);
void	line(t_mlx *mlx,double x1, double y1, double x2, double y2);
void	ft_hook(mlx_key_data_t keydata, void *param);

void	move_player(void *par);
int		collision(t_player *player, double next_x, double next_y);
void	raycasting(t_player *player);
int		isup(t_player *player);
int		isdown(t_player *player);
int		isright(t_player *player);
int		isleft(t_player *player);
void	wall_projection(t_player *player, int i);
int		ft_isdigit(int c);
void	esc(t_player *player);
void	rotate(t_player *player);
void	up_down(t_player *player);
void	left_right(t_player *player);
double	ft_normalize(t_player *player);
double	distance(t_player *player, int c);
double	xyhorizonral(t_player *player);
double	xyVertical(t_player *player);
void	raycasting(t_player *player);

#endif
