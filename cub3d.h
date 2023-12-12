/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:31:02 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/11 19:23:01 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "mlx42.h"

#define PI   3.14159f
#define WIDTH 15
#define HEIGHT 11
#define CUBE 64

typedef struct s_mlx
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	double			coord1;
	double			coord2;
}t_mlx;

typedef struct s_player
{
	double	x;
	double	y;
	double	radius;
	double	rotationAngle;
	double	moveSpeed;
	double	rotationSpeed;
	t_mlx	*mlx;
	char	**map;
}t_player;

void	set_up_window(t_mlx *mlx, t_player *player);
void	keep_window_opened(t_mlx *mlx, t_player *player);
void	create_2d_map(t_mlx *mlx, char **map);
void	set_up_player(t_player *player, t_mlx *mlx);
void	rect(t_mlx *mlx, int x, int y, int color);
void	circle(t_player *player, t_mlx *mlx);
void	line(t_mlx *mlx,double x1, double y1, double x2, double y2);
void	ft_hook(void *param);
void	move_player(t_player *player, t_mlx *mlx);
void	key_a(t_player *player);
void	move_right(t_player *player);
void	key_d(t_player *player);
void	move_left(t_player *player);
void	move_up(t_player *player);
void	move_down(t_player *player);
int		collision(t_player *player, double next_x, double next_y);
#endif